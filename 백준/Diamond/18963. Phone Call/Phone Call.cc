#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> tree[100005];
vector<pair<ll, pair<pii, pii>>> edge;
ll par[100005][21], level[100005];

struct DSU {
    int N;
    vector<ll> par, sz, v;
    
    DSU(int n) {
        N = n;
        par.resize(n + 5), sz.resize(n + 5), v.resize(n + 5);
        for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1, v[i] = 0;
    }
    
    int find(int n) {
        if (par[n] == n) return par[n];
        else return par[n] = find(par[n]);
    }
    
    void merge(int a, int b, ll w = 0) {
        a = find(a), b = find(b);
        if (a == b) return;
        sz[b] += sz[a];
        v[b] += (v[a] + w);
        par[a] = b;
    }
};

void DFS(int node, int lv, int p) {
    level[node] = lv;
    par[node][0] = p;
    
    for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
    
    for (int next: tree[node]) {
        if (next == p) continue;
        DFS(next, lv + 1, node);
    }
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

void going_up(int a, int lca, ll w, DSU &dsu1, DSU &dsu2) {
    int now = dsu2.find(a);
    while (level[now] > level[lca]) {
        dsu1.merge(now, par[now][0], w);
        dsu2.merge(now, par[now][0]);
        now = dsu2.find(par[now][0]);
    }
}

void solve() {
    cin >> N >> M;
    
    DSU dsu1(N), dsu2(N);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1, 1, 1);
    
    for (int i = 0; i < M; i++) {
        int a, b, c, d, w;
        cin >> a >> b >> c >> d >> w;
        edge.push_back({w, {{a, b}, {c, d}}});
    }
    
    sort(edge.begin(), edge.end());
    
    
    for (int i = 0; i < M; i++) {
        ll a, b, c, d, w;
        a = edge[i].second.first.first, b = edge[i].second.first.second, c = edge[i].second.second.first, d = edge[i].second.second.second;
        w = edge[i].first;
        
        int lca = LCA(a, b);
        going_up(a, lca, w, dsu1, dsu2);
        going_up(b, lca, w, dsu1, dsu2);
        
        lca = LCA(c, d);
        going_up(c, lca, w, dsu1, dsu2);
        going_up(d, lca, w, dsu1, dsu2);
        
        dsu1.merge(a, c, w);
    }
    
    int one = dsu1.find(1);
    
    cout << dsu1.sz[one] << " " << dsu1.v[one];
    
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