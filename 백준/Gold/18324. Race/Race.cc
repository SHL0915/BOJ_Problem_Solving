#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll K, N;

void solve() {
    cin >> K >> N;
    while (N--) {
        ll X;
        cin >> X;

        if (X * (X + 1) / 2 >= K) {
            ll l = 1, r = X, ans = -1;
            while (l <= r) {
                ll mid = (l + r) / 2;
                ll sum = mid * (mid + 1) / 2;
                if (sum >= K) {
                    ans = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            cout << ans << '\n';
        } else {
            ll l = 1, r = 1000000000, ans = -1;
            while (l <= r) {
                ll mid = (l + r) / 2;
                ll sum = mid * (mid + 1) - mid - (X - 1) * X / 2;
                if (sum > K) r = mid - 1;
                else {
                    ans = mid;
                    l = mid + 1;
                }
            }

            ll sum = ans * (ans + 1) - ans - (X - 1) * X / 2;
            if (sum == 0) cout << ans + (ans - X) << '\n';
            else cout << ans + (ans - X) + (K - sum - 1) / ans + 1 << '\n';
        }
    }
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