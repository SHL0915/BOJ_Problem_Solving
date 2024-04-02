#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 305;
const int INF = 0x3f3f3f3f;

vector<int> graph[sz];
int N, M;
int A[105], B[105];
int cap[sz][sz], flow[sz][sz], cost[sz][sz];
pii adj[sz][sz];

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
        vector<int> par(sz, -1), dist(sz, INF), mark(sz, 0);
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
        cin >> A[i];
        add_edge(S, i, A[i], 0);
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
        add_edge(N + i, E, B[i], 0);
    }
    
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) cin >> adj[j][i].first;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) cin >> adj[j][i].second;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!adj[i][j].first) continue;
            add_edge(i, N + j, adj[i][j].first, adj[i][j].second);
        }
    }
    
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