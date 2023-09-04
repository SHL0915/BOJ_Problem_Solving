#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
pair<pii, ll> A[205], B[205];
ll arr[205][205], flow[205][205], cap[205][205], cost[205][205];
vector<int> graph[205];

inline ll dist(pii a, pii b) {
    ll dx = abs(a.first - b.first);
    ll dy = abs(a.second - b.second);
    return dx + dy + 1;
}

void add_edge(int u, int v, int ca, int co) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = ca;
    cost[u][v] = co;
    cost[v][u] = -co;
    return;
}

pii MCMF(int s, int e) {
    ll mf = 0, mc = 0;
    while (1) {
        vector<ll> par(205, -1), dist(205, INF), mark(205, 0);
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
        ll val = INF;
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
        int x, y, b;
        cin >> x >> y >> b;
        A[i] = {{x, y}, b};
        add_edge(S, i, b, 0);
    }

    for (int i = 1; i <= M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        B[i] = {{x, y}, c};
        add_edge(N + i, E, c, 0);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ll c = dist(A[i].first, B[j].first);
            add_edge(i, N + j, INF, c);
        }
    }

    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            sum += arr[i][j] * dist(A[i].first, B[j].first);
        }
    }

    pii ans = MCMF(S, E);

    if (ans.second == sum) cout << "OPTIMAL";
    else {
        cout << "SUBOPTIMAL\n";
        for (int i = 1; i <= N; i++) {
            for (int j = N + 1; j <= N + M; j++) cout << flow[i][j] << " ";
            cout << '\n';
        }
    }

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