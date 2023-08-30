#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A, B;

void solve() {
    cin >> A >> B;
    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ll now = (1 << i);
        int cnt = 0;
        if (A & now) cnt++;
        if (B & now) cnt++;
        if (cnt == 1) ans += now;
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