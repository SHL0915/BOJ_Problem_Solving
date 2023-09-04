#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, cnt;
vector<int> tree[300005];
pii arr[300005], id[300005];
int par[300005][20], level[300005], seg[600005];

void update(int pos, int val) {
    for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

void DFS(int node, int p, int lv) {
    id[node].first = ++cnt;
    par[node][0] = p;
    level[node] = lv;
    for (int i = 1; i < 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
    for (int next: tree[node]) DFS(next, node, lv + 1);
    id[node].second = cnt;
    return;
}

int find(int node, int val) {
    for (int i = 0; i < 20; i++) {
        int p = par[node][i];
        if (query(id[p].first, id[p].second) >= val) {
            if (i == 0) return p;
            else return find(par[node][i - 1], val);
        }
    }
    return 0;
}

void solve() {
    cin >> N >> S;
    for (int i = 2; i <= N + 1; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].second++;
        tree[arr[i].second].push_back(i);
    }

    DFS(1, 0, 1);
    id[0] = {0, N + 1};
    update(id[1].first, S);

    for (int i = 2; i <= N + 1; i++) {
        int q = find(i, arr[i].first);
        cout << level[i] - level[q] - 1 << '\n';
        update(id[i].first, arr[i].first);
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