#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, cnt;
int arr[100005], p[100005][21], in_mst[200005], level[100005], sz[100005], head[100005];
int seg[4 * 100005], lazy[4 * 100005];
pii id[100005];
vector<int> tree[100005];
vector<pair<int, pii>> edge;

void ETT(int node) {
    id[node].first = ++cnt;
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if (next == p[node][0]) continue;
        if (!i) head[next] = head[node];
        else head[next] = next;
        ETT(next);
    }
    id[node].second = cnt;
    return;
}

void update_lazy(int n, int s, int e) {
    if (lazy[n] != INF) {
        seg[n] = min(seg[n], lazy[n]);
        if (s != e) {
            lazy[n * 2] = min(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = min(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = INF;
    }
    return;
}

void update_seg(int n, int s, int e, int l, int r, int v) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        lazy[n] = min(lazy[n], v);
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update_seg(n * 2, s, m, l, r, v);
    update_seg(n * 2 + 1, m + 1, e, l, r, v);
    seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
    return;
}

int query_seg(int n, int s, int e, int idx) {
    update_lazy(n, s, e);
    if (idx < s || idx > e) return INF;
    if (s == e) return seg[n];
    int m = (s + e) / 2;
    return min(query_seg(n * 2, s, m, idx), query_seg(n * 2 + 1, m + 1, e, idx));
}

void update(int a, int b, int v) {
    while (head[a] != head[b]) {
        if (level[a] < level[b]) swap(a, b);
        int st = p[head[a]][0];
        update_seg(1, 1, N, id[head[a]].first, id[a].first, v);
        a = st;
    }
    if (level[a] > level[b]) swap(a, b);
    update_seg(1, 1, N, id[a].first, id[b].first, v);
    return;
}


int find(int a, vector<int> &par) {
    if (par[a] == a) return par[a];
    else return par[a] = find(par[a], par);
}

void merge(int a, int b, vector<int> &par) {
    par[find(b, par)] = find(a, par);
    return;
}

void DFS(int node, int par, int lv) {
    sz[node] = 1;
    p[node][0] = par;
    level[node] = lv;
    for (int i = 1; i <= 20; i++) p[node][i] = p[p[node][i - 1]][i - 1];
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if (next == par) continue;
        DFS(next, node, lv + 1);
        sz[node] += sz[next];
        if (sz[tree[node][0]] < sz[next]) swap(tree[node][0], tree[node][i]);
    }
    return;
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 20; i >= 0; i--) {
            if (level[p[a][i]] >= level[b]) a = p[a][i];
        }
    }
    int ret = a;
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (p[a][i] != p[b][i]) {
                a = p[a][i];
                b = p[b][i];
            }
            ret = p[a][i];
        }
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        int w = abs(arr[u] - arr[v]);
        edge.push_back({w, {u, v}});
    }
    
    sort(edge.begin(), edge.end());
    
    vector<int> mst(N + 1), node(N + 1);
    iota(mst.begin(), mst.end(), 0);
    iota(node.begin(), node.end(), 0);
    
    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i].second.first, v = edge[i].second.second, w = edge[i].first;
        if (find(u, mst) == find(v, mst)) continue;
        else {
            in_mst[i] = 1;
            tree[u].push_back(v);
            tree[v].push_back(u);
            merge(u, v, mst);
        }
    }
    
    DFS(1, 1, 0);
    ETT(1);
    
    memset(seg, INF, sizeof(seg));
    memset(lazy, INF, sizeof(lazy));
    
    for (int i = 0; i < edge.size(); i++) {
        if (in_mst[i]) continue;
        int u = edge[i].second.first, v = edge[i].second.second, w = edge[i].first;
        if (find(u, node) == find(v, node)) continue;
        int lca = LCA(u, v);
        
        update(u, lca, w);
        update(v, lca, w);
    }
    
    for (int i = 1; i <= N; i++) {
        int q = query_seg(1, 1, N, id[i].first);
        cout << (q != INF ? q : -1) << " ";
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