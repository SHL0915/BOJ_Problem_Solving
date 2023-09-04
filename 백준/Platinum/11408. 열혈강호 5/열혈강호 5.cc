#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
vector<int> graph[805];
int cap[805][805], flow[805][805], cost[805][805];

void add_edge(int u, int v, int ca, int co) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = ca;
    cost[u][v] = co;
    cost[v][u] = -co;
    return;
}

pii MCMF(int s, int e) {
    int mf = 0, mc = 0;
    while (1) {
        int par[805], dist[805], mark[805];
        memset(par, -1, sizeof(par));
        memset(dist, INF, sizeof(dist));
        memset(mark, 0, sizeof(mark));
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        mark[s] = 1;
        while (q.size()) {
            int now = q.front();
            q.pop();
            mark[now] = 0;
            for (int next: graph[now]) {
                if (cap[now][next] - flow[now][next] > 0 && dist[next] > dist[now] + cost[now][next]) {
                    dist[next] = dist[now] + cost[now][next];
                    par[next] = now;
                    if (mark[next] == 0) {
                        mark[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        if (par[e] == -1) break;
        int val = INF;
        for (int i = e; i != s; i = par[i]) val = min(val, cap[par[i]][i] - flow[par[i]][i]);
        for (int i = e; i != s; i = par[i]) {
            mc += val * cost[par[i]][i];
            flow[par[i]][i] += val;
            flow[i][par[i]] -= val;
        }
        mf += val;
    }
    return {mf, mc};
}

void solve() {
    cin >> N >> M;
    int S = 0, E = N + M + 1;
    for (int i = 1; i <= N; i++) {
        int k;
        add_edge(S, i, 1, 0);
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            add_edge(i, N + a, 1, b);
        }
    }

    for (int i = 1; i <= M; i++) add_edge(N + i, E, 1, 0);

    pii ans = MCMF(S, E);

    cout << ans.first << '\n' << ans.second;
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