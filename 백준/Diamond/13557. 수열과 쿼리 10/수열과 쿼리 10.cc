#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct node {
    ll lsum = -INF, rsum = -INF, tot = -INF, max_sum = -INF, n = 0;
};

int N, M;
ll arr[100005], psum[100005];
node seg[400005];

node merge(node a, node b) {
    node ret;
    if (a.n == 0) return b;
    else if (b.n == 0) return a;
    else {
        ret.lsum = max(a.lsum, a.tot + b.lsum);
        ret.rsum = max(b.rsum, b.tot + a.rsum);
        ret.tot = a.tot + b.tot;
        ret.max_sum = max({a.max_sum, b.max_sum, a.rsum + b.lsum});
        ret.n = a.n + b.n;
    }
    return ret;
}

void update(int n, int s, int e, int pos, ll val) {
    if (pos > e || pos < s) return;
    if (s == e) {
        seg[n] = {val, val, val, val, 1};
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, pos, val);
    update(n * 2 + 1, m + 1, e, pos, val);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return;
}

node query(int n, int s, int e, int l, int r) {
    if (l > e || r < s) return {-INF, -INF, -INF, -INF, 0};
    else if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return merge(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }
    for (int i = 1; i <= N; i++) psum[i] = arr[i] + psum[i - 1];
    
    cin >> M;
    while (M--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        if (c > b) {
            node q1 = query(1, 1, N, a, b);
            node q2 = query(1, 1, N, c, d);
            cout << q1.rsum + (psum[c - 1] - psum[b]) + q2.lsum << '\n';
        } else {
            node q1 = query(1, 1, N, a, c);
            node q2 = query(1, 1, N, c, b);
            node q3 = query(1, 1, N, b, d);
            ll ans = -INF;
            ans = max(ans, q1.rsum + q2.lsum - arr[c]);
            ans = max(ans, q1.rsum + q3.lsum + (psum[b] - psum[c - 1]) - (arr[b] + arr[c]));
            ans = max(ans, q2.max_sum);
            ans = max(ans, q2.rsum + q3.lsum - arr[b]);
            cout << ans << '\n';
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