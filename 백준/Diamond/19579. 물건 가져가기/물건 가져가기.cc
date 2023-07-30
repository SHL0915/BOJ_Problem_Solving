#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector<int> graph[205];
int cap[205][205], flow[205][205];
int level[205], mark[205], arr[205], vst[205];
vector<int> ans;

void add_edge(int s, int e, int c) {
    graph[s].push_back(e);
    graph[e].push_back(s);
    cap[s][e] = c;
    return;
}

int DFS(int S, int E, int F) {
    if (S == E) return F;

    for (int &i = mark[S]; i < graph[S].size(); i++) {
        int next = graph[S][i];
        if (level[next] == level[S] + 1 && cap[S][next] - flow[S][next] > 0) {
            int ret = DFS(next, E, min(F, cap[S][next] - flow[S][next]));
            if (ret) {
                flow[S][next] += ret;
                flow[next][S] -= ret;
                return ret;
            }
        }
    }

    return 0;
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
        while (1) {
            int res = DFS(S, E, INF);
            if (res) ret += res;
            else break;
        }
    }

    return ret;
}

void chk(int node) {
    if (vst[node]) return;
    vst[node] = 1;
    if (node != 0) ans.push_back(node);

    for (int next: graph[node]) {
        if (vst[next]) continue;
        if (cap[node][next] - flow[node][next] > 0) chk(next);
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] >= 0) add_edge(0, i, arr[i]);
        else add_edge(i, N + 1, -arr[i]);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, INF);
    }

    Dinic(0, N + 1);
    chk(0);

    cout << ans.size() << '\n';
    for (int i: ans) cout << i << " ";

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