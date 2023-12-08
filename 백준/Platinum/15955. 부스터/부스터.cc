#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, Q;
pair<int, pii> arr[250005];
vector<pair<ll, pii>> edge;
vector<pii> tree[250005];
ll parent[250005], level[250005], par[250005][25], table[250005][25];

int find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(a)] = find(b);
    return;
}

void DFS(int node, int p, int lv, ll val) {
    par[node][0] = p;
    table[node][0] = val;
    level[node] = lv;
    for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
    for (int i = 1; i <= 20; i++) table[node][i] = max(table[node][i - 1], table[par[node][i - 1]][i - 1]);
    for (auto &[next, cost]: tree[node]) {
        if (next == p) continue;
        DFS(next, node, lv + 1, cost);
    }
    return;
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 20; i >= 0; i--) {
            if (level[par[a][i]] >= level[b]) a = par[a][i];
        }
    }
    int ret = a;
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
            ret = par[a][i];
        }
    }
    return ret;
}

ll query(int a, int b) {
    if (a == b) return 0;
    ll ret = -1;
    for (int i = 20; i >= 0; i--) {
        if (level[par[b][i]] >= level[a]) {
            ret = max(ret, table[b][i]);
            b = par[b][i];
        }
    }
    return ret;
}

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {i, {x, y}};
        parent[i] = i;
    }
    
    sort(arr + 1, arr + N + 1, [&](pair<int, pii> a, pair<int, pii> b) {
        return a.second.first < b.second.first;
    });
    for (int i = 2; i <= N; i++) {
        edge.push_back({arr[i].second.first - arr[i - 1].second.first, {arr[i].first, arr[i - 1].first}});
    }
    
    sort(arr + 1, arr + N + 1, [&](pair<int, pii> a, pair<int, pii> b) {
        return a.second.second < b.second.second;
    });
    for (int i = 2; i <= N; i++) {
        edge.push_back({arr[i].second.second - arr[i - 1].second.second, {arr[i].first, arr[i - 1].first}});
    }
    
    sort(edge.begin(), edge.end());
    int cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (cnt == N - 1) break;
        ll cost = edge[i].first;
        int a = edge[i].second.first, b = edge[i].second.second;
        if (find(a) == find(b)) continue;
        else {
            tree[a].push_back({b, cost});
            tree[b].push_back({a, cost});
            merge(a, b);
            cnt++;
        }
    }
    
    DFS(1, 1, 1, 0);
    
    while (Q--) {
        ll a, b, x;
        cin >> a >> b >> x;
        int lca = LCA(a, b);
        ll ans = max(query(lca, a), query(lca, b));
        if (ans > x) cout << "NO\n";
        else cout << "YES\n";
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