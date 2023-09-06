#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct edge {
    int to, cap, cost, rev;
};

int N, M;
vector<edge> graph[505];
int A[505], B[505];

void init() {
    for (int i = 0; i <= N + 1; i++) graph[i].clear();
    return;
}

void add_edge(int u, int v, int ca, int co) {
    graph[u].push_back({v, ca, co, (int) graph[v].size()});
    graph[v].push_back({u, 0, -co, (int) graph[u].size() - 1});
    return;
}

pii MCMF(int s, int e) {
    int mf = 0, mc = 0;
    while (1) {
        vector<int> par(N + 5, -1), dist(N + 5, INF), mark(N + 5, 0), idx(N + 5, -1);
        queue<int> q;
        q.push(s);
        mark[s] = 1;
        dist[s] = 0;
        while (q.size()) {
            int now = q.front();
            q.pop();
            mark[now] = 0;
            int cnt = 0;
            for (auto next: graph[now]) {
                if (next.cap > 0 && dist[next.to] > dist[now] + next.cost) {
                    dist[next.to] = dist[now] + next.cost;
                    par[next.to] = now;
                    idx[next.to] = cnt;
                    if (mark[next.to] == 0) {
                        mark[next.to] = 1;
                        q.push(next.to);
                    }
                }
                cnt++;
            }
        }
        if (par[e] == -1) break;
        int val = INF;
        for (int i = e; i != s; i = par[i]) val = min(val, graph[par[i]][idx[i]].cap);
        for (int i = e; i != s; i = par[i]) {
            mc += val * graph[par[i]][idx[i]].cost;
            graph[par[i]][idx[i]].cap -= val;
            int r = graph[par[i]][idx[i]].rev;
            graph[i][r].cap += val;
        }
        mf += val;
    }
    
    return {mf, mc};
}

void solve() {
    cin >> N >> M;
    init();
    
    int S = 0, E = N + 1;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, INF, 1);
        add_edge(b, a, INF, 1);
    }
    
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    
    for (int i = 1; i <= N; i++) {
        if (A[i] != B[i]) {
            if (A[i] == 0) add_edge(S, i, 1, 0);
            else add_edge(i, E, 1, 0);
        }
    }
    
    cout << MCMF(S, E).second << endl;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}