#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector<int> graph[305];
int flow[305][305], cap[305][305];
int mark[305], level[305];

int DFS(int S, int E, int F) {
    if (S == E) return F;
    int ret = 0;

    for (int &i = mark[S]; i < graph[S].size(); i++) {
        int next = graph[S][i];
        if (level[next] == level[S] + 1 && cap[S][next] - flow[S][next] > 0) {
            ret = DFS(next, E, min(F, cap[S][next] - flow[S][next]));
            if (ret) {
                flow[S][next] += ret;
                flow[next][S] -= ret;
                return ret;
            }
        }
    }

    return ret;
}

int BFS(int S, int E) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[S] = 0;
    q.push(S);

    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int next: graph[now]) {
            if (level[next] == -1 && cap[now][next] - flow[now][next] > 0) {
                level[next] = level[now] + 1;
                q.push(next);
            }
        }
    }

    return level[E] != -1;
}

int Dinic(int S, int E) {
    int ret = 0;
    while (BFS(S, E)) {
        memset(mark, 0, sizeof(mark));
        int res;
        while (res = DFS(S, E, INF)) ret += res;
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cap[a][b] += c;
        cap[b][a] += c;
    }

    cout << Dinic(1, N);
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}