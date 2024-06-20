#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<ll> arr[15 * 40];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[a * 35 + b].push_back(c * 35 + d);
    }

    ll mval = 0;
    ll now = 3 * 35 + 1;

    ll ptr = 0, ans = 0;
    while (1) {
        if (now > 11 * 35 + 30) break;

        for (; ptr <= now; ptr++) {
            for (ll a: arr[ptr]) mval = max(mval, a);
        }

        if (mval <= now) {
            cout << 0;
            return;
        }

        ans++;
        now = mval;
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