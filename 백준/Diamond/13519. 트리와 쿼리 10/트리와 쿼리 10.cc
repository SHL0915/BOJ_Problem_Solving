#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct Node {
    ll l, r, tot, max;
};

int N, M, cnt;
vector<int> graph[100005], tree[100005];
ll arr[100005], par[100005], level[100005], head[100005], id[100005], sz[100005];
Node seg[400005];
ll lazy[400005];

void make_tree(int node, int p) {
    for (int next: graph[node]) {
        if (next == p) continue;
        tree[node].push_back(next);
        par[next] = node;
        make_tree(next, node);
    }
    return;
}

void DFS(int node, int lv) {
    sz[node] = 1;
    level[node] = lv;
    for (int &next: tree[node]) {
        DFS(next, lv + 1);
        sz[node] += sz[next];
        if (sz[next] > sz[tree[node][0]]) swap(next, tree[node][0]);
    }
    return;
}

void ETT(int node) {
    id[node] = ++cnt;
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i];
        if (i == 0) head[next] = head[node];
        else head[next] = next;
        ETT(next);
    }
    return;
}

Node merge(Node a, Node b) {
    Node ret;
    ret.l = max({a.l, a.tot + b.l, 0LL});
    ret.r = max({b.r, b.tot + a.r, 0LL});
    ret.tot = a.tot + b.tot;
    ret.max = max({a.r + b.l, a.max, b.max, 0LL});
    return ret;
}

Node flip(Node a) {
    return {a.r, a.l, a.tot, a.max};
}

void update_lazy(int n, ll s, ll e) {
    if (lazy[n] != INF) {
        seg[n].l = seg[n].r = seg[n].max = max(0LL, (e - s + 1) * lazy[n]);
        seg[n].tot = (e - s + 1) * lazy[n];
        if (s != e) {
            lazy[n * 2] = lazy[n];
            lazy[n * 2 + 1] = lazy[n];
        }
        lazy[n] = INF;
    }
    return;
}

void update(int n, int s, int e, int l, int r, ll v) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        lazy[n] = v;
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, l, r, v);
    update(n * 2 + 1, m + 1, e, l, r, v);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return;
}

Node query(int n, int s, int e, int l, int r) {
    update_lazy(n, s, e);
    if (l > e || r < s) return {0, 0, 0, 0};
    if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return merge(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

Node tree_query(int a, int b) {
    if (id[a] > id[b]) swap(a, b);
    Node A = {0, 0, 0, 0}, B = {0, 0, 0, 0};
    while (head[a] != head[b]) {
        if (level[head[a]] <= level[head[b]]) {
            int st = head[b];
            B = merge(query(1, 1, N, id[st], id[b]), B);
            b = par[st];
        } else {
            int st = head[a];
            A = merge(query(1, 1, N, id[st], id[a]), A);
            a = par[st];
        }
    }

    if (level[a] > level[b]) A = merge(query(1, 1, N, id[b], id[a]), A);
    else B = merge(query(1, 1, N, id[a], id[b]), B);

    return merge(flip(A), B);
}

void tree_update(int a, int b, int v) {
    while (head[a] != head[b]) {
        if (level[head[a]] < level[head[b]]) swap(a, b);
        int st = head[a];
        update(1, 1, N, id[st], id[a], v);
        a = par[st];
    }
    if (level[a] > level[b]) swap(a, b);
    update(1, 1, N, id[a], id[b], v);
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    make_tree(1, 1);
    DFS(1, 1);

    head[1] = 1;
    ETT(1);

    for (int i = 0; i <= 4 * N; i++) lazy[i] = INF;
    for (int i = 1; i <= N; i++) update(1, 1, N, id[i], id[i], arr[i]);

    cin >> M;

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            Node q = tree_query(b, c);
            cout << q.max << '\n';
        } else {
            int d;
            cin >> d;
            tree_update(b, c, d);
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