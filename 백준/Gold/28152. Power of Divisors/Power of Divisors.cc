#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll X;

int chk(__int128 k, int n) {
    __int128 now = 1;
    for (int i = 0; i < n; i++) {
        now *= k;
        if (now > X) return 0;
    }

    if (now == X) return 1;
    else return 2;
}

void solve() {
    cin >> X;

    if (X == 1) {
        cout << 1;
        return;
    }

    for (int i = 64; i >= 2; i--) {
        __int128 l = 1, r = 1000000000;
        __int128 ans = -1;
        while (l <= r) {
            __int128 mid = (l + r) / 2;
            int res = chk(mid, i);

            if (res) {
                if (res == 1) {
                    ans = mid;
                    break;
                } else l = mid + 1;
            } else r = mid - 1;
        }
        if (ans == -1) continue;
        else {
            int cnt = 0;
            for (ll i = 1; i * i <= ans; i++) {
                if (ans % i) continue;
                if (ans == i * i) cnt++;
                else cnt += 2;
            }

            if (cnt == i) {
                cout << (ll) ans;
                return;
            }
        }
    }

    cout << -1;
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