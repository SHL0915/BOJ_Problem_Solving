#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int seg[8005005], lazy[8005005];
int sparse[2000005][21];

void update_lazy(int n, int s, int e) {
    if (lazy[n]) {
        seg[n] = max(seg[n], lazy[n]);
        if (s != e) {
            lazy[n * 2] = max(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = max(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = 0;
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        lazy[n] = max(lazy[n], v);
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, l, r, v);
    update(n * 2 + 1, m + 1, e, l, r, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
    return;
}

int query(int n, int s, int e, int idx) {
    update_lazy(n, s, e);
    if (idx > e || idx < s) return 0;
    if (s == e) return seg[n];
    int m = (s + e) / 2;
    return max(query(n * 2, s, m, idx), query(n * 2 + 1, m + 1, e, idx));
}

int q(int idx) {
    int l = idx, r = idx + N;
    int ret = 0;
    for (int i = 20; i >= 0; i--) {
        int next = sparse[l][i];
        if (!next) continue;
        if (next >= r) continue;
        l = next;
        ret += (1 << i);
    }
    
    if (sparse[l][0] >= r) return ret + 1;
    else return 1e9;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        if (b < a) b += N;
        update(1, 1, 2 * N, a, b, b + 1);
    }
    
    for (int i = 1; i <= 2 * N; i++) sparse[i][0] = query(1, 1, 2 * N, i);
    
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 2 * N; j++) sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
    }
    
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, q(i));
    }
    
    if (ans == 1e9) cout << "impossible";
    else cout << ans;
    
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