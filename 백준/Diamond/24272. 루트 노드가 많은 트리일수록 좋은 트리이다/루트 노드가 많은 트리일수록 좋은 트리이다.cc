#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 100005;

int N, Q, idx;
int seg[4 * sz], cnt[4 * sz], p[sz], now[sz];
pii id[sz];
vector<int> tree[sz];
vector<pair<pii, int>> edge;

void DFS(int node, int par) {
    id[node].first = ++idx;
    p[node] = par;
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node);
    }
    id[node].second = idx;
}

void update(int n, int s, int e, int l, int r, int v) {
    if (l > e || r < s) return;
    if (l <= s && e <= r) seg[n] += v;
    else {
        int m = (s + e) / 2;
        update(n * 2, s, m, l, r, v);
        update(n * 2 + 1, m + 1, e, l, r, v);
    }

    if (seg[n]) cnt[n] = e - s + 1;
    else {
        if (s == e) cnt[n] = 0;
        else cnt[n] = cnt[n * 2] + cnt[n * 2 + 1];
    }
}

int query() {
    return N - cnt[1];
}

void change(int u, int v, int t) {
    if (now[v] == t) return;

    if (now[v] != 2) {
        if (!now[v]) {
            update(1, 1, N, id[v].first, id[v].second, -1);
        } else {
            update(1, 1, N, 1, id[v].first - 1, -1);
            update(1, 1, N, id[v].second + 1, N, -1);
        }
    }

    now[v] = t;
    if (t == 0) {
        update(1, 1, N, id[v].first, id[v].second, 1);
    } else if (t == 1) {
        update(1, 1, N, 1, id[v].first - 1, 1);
        update(1, 1, N, id[v].second + 1, N, 1);
    }
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        string s;
        cin >> a >> s >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        int t;
        if (s == "--") t = 2;
        else if (s == "->") t = 0;
        else t = 1;
        edge.push_back({{a, b}, t});
    }

    DFS(1, 0);

    for (int i = 1; i <= N; i++) now[i] = 2;

    for (auto [a, b]: edge) {
        int u = a.first, v = a.second;
        if (b == 2) continue;
        if (p[v] != u) swap(u, v), b ^= 1;
        change(u, v, b);
    }

    cin >> Q;
    while (Q--) {
        int u, v;
        string s;
        cin >> u >> s >> v;
        int t;
        if (s == "--") t = 2;
        else if (s == "->") t = 0;
        else t = 1;

        if (p[v] != u) {
            swap(u, v);
            if (t != 2) t ^= 1;
        }

        change(u, v, t);

        cout << query() << '\n';
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