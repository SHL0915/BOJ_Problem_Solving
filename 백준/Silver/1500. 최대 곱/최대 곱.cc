#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll S, K;

void solve() {
    cin >> S >> K;

    ll a = S / K, b = S % K;

    vector<ll> v;
    for (int i = 0; i < K; i++) {
        if (i < b) v.push_back(a + 1);
        else v.push_back(a);
    }

    ll ans = 1;
    for (ll i: v) ans *= i;

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