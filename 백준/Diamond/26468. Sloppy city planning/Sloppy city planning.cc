#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
ll cost[3005][3005];
int par[3005], id[3005], in_degree[3005], out_degree[3005], cnt, id_cnt;
vector<pii> graph[3005];
ll dist[3005];
stack<int> st;

int DFS(int node) {
    par[node] = ++cnt;
    int ret = par[node];
    st.push(node);
    
    for (int i = 1; i <= N; i++) {
        if (cost[node][i] <= 0) continue;
        if (!par[i]) ret = min(ret, DFS(i));
        else if (!id[i]) ret = min(ret, par[i]);
    }
    
    if (ret == par[node]) {
        id_cnt++;
        while (1) {
            int t = st.top();
            st.pop();
            id[t] = id_cnt;
            if (t == node) break;
        }
    }
    
    return ret;
}

void Dijkstra(int node) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, node});
    dist[node] = 0;
    
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        ll now = t.second, val = t.first;
        
        if (dist[now] < val) continue;
        
        for (auto i: graph[now]) {
            ll next = i.first, cost = i.second;
            if (dist[next] > val + cost) {
                dist[next] = val + cost;
                pq.push({dist[next], next});
            }
        }
    }
    
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            cin >> cost[i][j];
            cost[j][i] = -cost[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) if (!par[i]) DFS(i);
    
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (id[i] == id[j]) continue;
            int u = id[i], v = id[j];
            if (cost[i][j] > 0) {
                graph[u].push_back({v, cost[i][j]});
                graph[v].push_back({u, 0});
                in_degree[v]++;
                out_degree[u]++;
            } else {
                graph[u].push_back({v, 0});
                graph[v].push_back({u, -cost[i][j]});
                in_degree[u]++;
                out_degree[v]++;
            }
        }
    }
    
    for (int i = 1; i <= id_cnt; i++) {
        if (!in_degree[i]) Dijkstra(i);
    }
    
    for (int i = 1; i <= id_cnt; i++) {
        if (!out_degree[i]) cout << dist[i];
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