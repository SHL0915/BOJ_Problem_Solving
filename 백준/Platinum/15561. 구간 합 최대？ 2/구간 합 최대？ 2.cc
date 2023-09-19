#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct node {
    int l = -INF, r = -INF, tot = 0, max = -INF;
};

int N, Q, U, V;
int arr[100005];
node seg[400005];

node merge(node a, node b) {
    return {
            max(a.l, a.tot + b.l),
            max(b.r, b.tot + a.r),
            a.tot + b.tot,
            max({a.max, b.max, a.r + b.l})
    };
}

void update(int n, int s, int e, int pos, int val) {
    if (pos > e || pos < s) return;
    if (s == e) {
        seg[n] = {val, val, val, val};
        return;
    }
    int mid = (s + e) / 2;
    update(n * 2, s, mid, pos, val);
    update(n * 2 + 1, mid + 1, e, pos, val);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return;
}

node query(int n, int s, int e, int l, int r) {
    if (l > e || r < s) return {-INF, -INF, 0, -INF};
    if (l <= s && e <= r) return seg[n];
    int mid = (s + e) / 2;
    return merge(query(n * 2, s, mid, l, r), query(n * 2 + 1, mid + 1, e, l, r));
}

void solve() {
    cin >> N >> Q >> U >> V;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i] * U + V);
    }
    
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            node res = query(1, 1, N, l, r);
            cout << res.max - V << '\n';
        } else {
            arr[l] = r;
            update(1, 1, N, l, r * U + V);
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