#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    ll L, both, non, R;

    node() {
        L = 0;
        both = 0;
        non = 0;
        R = 0;
    }
};

int N, D;
node seg[160005];

void update(int n, int s, int e, int idx, ll val) {
    if (idx > e || idx < s) return;
    if (s == e) {
        node &now = seg[n];
        now.L = 0;
        now.R = 0;
        now.non = 0;
        now.both = val;
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, idx, val);
    update(n * 2 + 1, m + 1, e, idx, val);

    node &now = seg[n];
    node &left = seg[n * 2];
    node &right = seg[n * 2 + 1];

    now.L = max(left.L + max(right.L, right.non), left.both + right.non);
    now.R = max(right.R + max(left.R, left.non), right.both + left.non);
    now.both = max(left.L + max(right.both, right.R), left.both + right.R);
    now.non = max(left.R + right.non, left.non + right.L);

    return;
}

node query(int n, int s, int e, int l, int r) {
    if (l > e || r < s) return node();
    if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    node ret;
    node left = query(n * 2, s, m, l, r);
    node right = query(n * 2 + 1, m + 1, e, l, r);

    ret.L = max(left.L + max(right.L, right.non), left.both + right.non);
    ret.R = max(right.R + max(left.R, left.non), right.both + left.non);
    ret.both = max(left.L + max(right.both, right.R), left.both + right.R);
    ret.non = max(left.R + right.non, left.non + right.L);

    return ret;
}

void solve() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        update(1, 1, N, i, a);
    }

    ll ans = 0;
    for (int i = 0; i < D; i++) {
        int a, b;
        cin >> a >> b;
        update(1, 1, N, a, b);
        node q = query(1, 1, N, 1, N);
        ans += max({q.L, q.R, q.both, q.non});
    }

    cout << ans;
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