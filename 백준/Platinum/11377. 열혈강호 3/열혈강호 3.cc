#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct edge {
    int to, cap, rev;
};

int N, M, K;
vector<edge> graph[2005];
int mark[2005], level[2005];

void add_edge(int u, int v, int c) {
    graph[u].push_back({v, c, (int) graph[v].size()});
    graph[v].push_back({u, 0, (int) graph[u].size() - 1});
    return;
}

int DFS(int s, int e, int f) {
    if (s == e) return f;
    for (int &i = mark[s]; i < graph[s].size(); i++) {
        edge &next = graph[s][i];
        if (level[next.to] == level[s] + 1 && next.cap > 0) {
            int ret = DFS(next.to, e, min(f, next.cap));
            if (ret) {
                next.cap -= ret;
                graph[next.to][next.rev].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}

bool BFS(int s, int e) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (auto next: graph[now]) {
            if (level[next.to] == -1 && next.cap) {
                level[next.to] = level[now] + 1;
                q.push(next.to);
            }
        }
    }
    return level[e] != -1;
}

int Dinic(int s, int e) {
    int ret = 0;
    while (BFS(s, e)) {
        memset(mark, 0, sizeof(mark));
        while (1) {
            int res = DFS(s, e, INF);
            if (res) ret += res;
            else break;
        }
    }
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    int S = 0, A = N + M + 1, B = N + M + 2, E = N + M + 3;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        add_edge(A, i, 1);
        add_edge(B, i, 1);
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a += N;
            add_edge(i, a, 1);
        }
    }

    for (int i = 1; i <= M; i++) add_edge(i + N, E, 1);
    add_edge(S, A, N);
    add_edge(S, B, K);

    cout << Dinic(S, E);
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