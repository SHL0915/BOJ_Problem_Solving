#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pair<pii, pii> path[2305];
int mark[2305], par[2305], id[2305], id_cnt, cnt;
stack<int> st;

int DFS(int node, vector<vector<ll>> &cost) {
    par[node] = ++cnt;
    int ret = cnt;
    st.push(node);
    for (int i = 1; i <= N; i++) {
        if (cost[node][i]) continue;
        int next = i;
        if (par[next] == 0) ret = min(ret, DFS(next, cost));
        else if (id[next] == 0) ret = min(ret, par[next]);
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

void Dijkstra(int start, vector<ll> &dist, vector<vector<pair<pii, pii>>> &ngraph) {
    fill(dist.begin(), dist.end(), 1e18);
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        ll now = t.second, val = t.first;
        if (dist[now] < val) continue;
        
        for (auto i: ngraph[now]) {
            ll nxt = i.first.first, cost = i.first.second, l = i.second.first, r = i.second.second;
            if (dist[nxt] > val + cost) {
                dist[nxt] = val + cost;
                pq.push({dist[nxt], nxt});
                path[nxt] = {{now, cost},
                             {l,   r}};
            }
        }
    }
}

void find_ans(int now, vector<pii> &v, int root) {
    if (now == root) return;
    if (mark[now]) return;
    mark[now] = 1;
    
    auto nxt = path[now];
    if (nxt.first.second != 0) v.push_back(nxt.second);
    
    find_ans(nxt.first.first, v, root);
    
    return;
}

void solve() {
    cin >> N;
    
    cnt = 0, id_cnt = 0;
    memset(par, 0, sizeof(par)), memset(mark, 0, sizeof(mark)), memset(id, 0, sizeof(id));
    
    vector<vector<ll>> cost(N + 1);
    vector<ll> dist(N + 1);
    vector<int> in_degree(N + 1, 0), out_degree(N + 1, 0);
    vector<vector<pair<pii, pii>>> ngraph;
    
    for (int i = 1; i <= N; i++) {
        cost[i].resize(N + 1);
        for (int j = 1; j <= N; j++) {
            cin >> cost[i][j];
        }
    }
    
    if (N == 2) {
        cout << "NO\n";
        return;
    }
    
    while (st.size()) st.pop();
    for (int i = 1; i <= N; i++) if (!par[i]) DFS(i, cost);
    
    ngraph.resize(id_cnt + 1);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cost[i][j]) continue;
            if (id[i] == id[j]) continue;
            ngraph[id[i]].push_back({{id[j], cost[j][i]},
                                     {i,     j}});
            ngraph[id[j]].push_back({{id[i], 0},
                                     {j,     i}});
            in_degree[id[j]]++;
            out_degree[id[i]]++;
        }
    }
    
    cout << "YES\n";
    
    ll ans = 0;
    int root = -1;
    for (int i = 1; i <= id_cnt; i++) {
        if (!in_degree[i]) root = i;
    }
    
    Dijkstra(root, dist, ngraph);
    
    vector<pii> v;
    
    for (int i = 1; i <= id_cnt; i++) {
        if (!out_degree[i]) ans += dist[i], find_ans(i, v, root);
    }
    
    cout << v.size() << " " << ans << endl;
    for (auto i: v) cout << i.second << " " << i.first << endl;
    
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