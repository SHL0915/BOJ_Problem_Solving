#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll T, X, M;
pii arr[1005];

void solve() {
    cin >> T >> X >> M;

    ll m = 1e18;
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        m = min(m, (a - 1) / b);
    }

    ll ans = 0;
    ll v = min(m, T);
    if (v == 0) {
        cout << 0;
        return;
    }
    ans += X * v;
    T -= v;
    T--;

    while (T > 0) {
        ans += X;
        T -= 2;
    }

    cout << ans << '\n';

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