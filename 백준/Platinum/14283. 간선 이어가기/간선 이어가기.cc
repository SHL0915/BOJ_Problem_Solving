#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, S, T;
vector<int> graph[55];
vector<pair<pii, int>> edge;
int flow[55][55], cap[55][55], level[55], mark[55];

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

    q.push(S);
    level[S] = 0;

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
    if (mark[node]) return;
    mark[node] = 1;
    for (int next: graph[node]) {
        if (cap[node][next] - flow[node][next] > 0) chk(next);
    }

    return;
}

void solve() {
    cin >> N >> M;
    ll tot = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{a, b}, c});
        tot += c;
    }
    cin >> S >> T;

    ll ans = 0;

    for (int i = 0; i < edge.size(); i++) {
        for (int j = 0; j <= N + 1; j++) graph[j].clear();
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        for (int j = 0; j < edge.size(); j++) {
            if (j == i) continue;
            int a = edge[j].first.first, b = edge[j].first.second, c = edge[j].second;
            graph[a].push_back(b);
            graph[b].push_back(a);
            cap[a][b] += c;
            cap[b][a] += c;
        }

        graph[0].push_back(S);
        cap[0][S] = INF;
        graph[T].push_back(N + 1);
        cap[T][N + 1] = INF;

        int res = Dinic(0, N + 1);
        memset(mark, 0, sizeof(mark));
        //chk(0);

        int a = edge[i].first.first, b = edge[i].first.second;
        if (cap[a][b] - flow[a][b] == 0) ans = max(ans, tot - res);
    }

    cout << ans;
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