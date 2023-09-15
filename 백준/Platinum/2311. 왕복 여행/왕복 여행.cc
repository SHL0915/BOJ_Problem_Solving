#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int SZ = 21505;

struct edge {
    int to, cap, cost, rev;
};

int N, M;
vector<edge> graph[SZ];

void add_edge(int u, int v, int ca, int co) {
    graph[u].push_back({v, ca, co, (int) graph[v].size()});
    graph[v].push_back({u, 0, -co, (int) graph[u].size() - 1});
    return;
}

pii MCMF(int s, int e) {
    int mc = 0, mf = 0;
    while (1) {
        vector<int> mark(SZ, 0), dist(SZ, INF), par(SZ, -1), idx(SZ, -1);
        queue<int> q;
        q.push(s);
        mark[s] = 1;
        dist[s] = 0;
        while (q.size()) {
            int now = q.front(), cnt = 0;
            q.pop();
            mark[now] = 0;
            for (auto next: graph[now]) {
                if (next.cap > 0 && dist[next.to] > dist[now] + next.cost) {
                    dist[next.to] = dist[now] + next.cost;
                    par[next.to] = now;
                    idx[next.to] = cnt;
                    if (mark[next.to] == 0) {
                        q.push(next.to);
                        mark[next.to] = 1;
                    }
                }
                cnt++;
            }
        }
        if (par[e] == -1) break;
        int flow = INF;
        for (int i = e; i != s; i = par[i]) flow = min(flow, graph[par[i]][idx[i]].cap);
        for (int i = e; i != s; i = par[i]) {
            mc += flow * graph[par[i]][idx[i]].cost;
            graph[par[i]][idx[i]].cap -= flow;
            int r = graph[par[i]][idx[i]].rev;
            graph[i][r].cap += flow;
        }
        mf += flow;
    }
    return {mf, mc};
}

void solve() {
    cin >> N >> M;
    int S = 0, E = N + 2 * M + 1;

    auto in = [&](int a) { return N + a * 2 - 1; };
    auto out = [&](int a) { return N + a * 2; };

    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, in(i), INF, 0);
        add_edge(b, in(i), INF, 0);
        add_edge(out(i), a, INF, 0);
        add_edge(out(i), b, INF, 0);
        add_edge(in(i), out(i), 1, c);
    }

    add_edge(S, 1, INF, 0);
    add_edge(N, E, 2, 0);

    cout << MCMF(S, E).second;
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