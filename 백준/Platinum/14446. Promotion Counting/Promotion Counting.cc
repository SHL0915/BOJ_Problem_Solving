#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt;
int arr[100005], rev[100005];
vector<int> tree[100005], seg[400005];
pii id[100005];

void DFS(int node) {
    id[node].first = ++cnt;
    rev[cnt] = node;
    for (int next: tree[node]) DFS(next);
    id[node].second = cnt;
    return;
}

void build(int n, int s, int e) {
    if (s == e) {
        seg[n].push_back(arr[rev[s]]);
        return;
    }
    int m = (s + e) / 2;
    build(n * 2, s, m);
    build(n * 2 + 1, m + 1, e);
    for (int i: seg[n * 2]) seg[n].push_back(i);
    for (int i: seg[n * 2 + 1]) seg[n].push_back(i);
    sort(seg[n].begin(), seg[n].end());
    return;
}

int query(int n, int s, int e, int l, int r, int v) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return (seg[n].size() - (upper_bound(seg[n].begin(), seg[n].end(), v) - seg[n].begin()));
    int m = (s + e) / 2;
    return query(n * 2, s, m, l, r, v) + query(n * 2 + 1, m + 1, e, l, r, v);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 2; i <= N; i++) {
        int a;
        cin >> a;
        tree[a].push_back(i);
    }
    DFS(1);

    build(1, 1, N);
    for (int i = 1; i <= N; i++) {
        cout << query(1, 1, N, id[i].first, id[i].second, arr[i]) << '\n';
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