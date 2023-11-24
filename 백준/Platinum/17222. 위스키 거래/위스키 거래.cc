#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;

struct edge {
    ll to, cap, rev;
};

vector<edge> graph[205];
ll arr[205], mark[205], level[205];

void add_edge(int u, int v, ll c) {
    graph[u].push_back({v, c, (int) graph[v].size()});
    graph[v].push_back({u, 0, (int) graph[u].size() - 1});
    return;
}

ll DFS(int s, int e, ll f) {
    if (s == e) return f;
    for (ll &i = mark[s]; i < graph[s].size(); i++) {
        edge &next = graph[s][i];
        if (level[next.to] == level[s] + 1 && next.cap > 0) {
            ll ret = DFS(next.to, e, min(f, next.cap));
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

ll Dinic(int s, int e) {
    ll ret = 0;
    while (BFS(s, e)) {
        memset(mark, 0, sizeof(mark));
        while (1) {
            ll res = DFS(s, e, INF);
            if (res) ret += res;
            else break;
        }
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        add_edge(i, 0, INF);
    }
    for (int i = N + 1; i <= N + M; i++) {
        cin >> arr[i];
        add_edge(N + M + 1, i, arr[i]);
    }
    for (int i = N + 1; i <= N + M; i++) {
        ll k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            ll a;
            cin >> a;
            add_edge(i, a, arr[a]);
        }
    }
    cout << Dinic(N + M + 1, 0);
    
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