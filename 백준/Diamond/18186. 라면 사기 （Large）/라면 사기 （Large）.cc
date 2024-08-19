#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, B, C;
ll arr[1000005];

void solve() {
    cin >> N >> B >> C;
    for (int i = 0; i < N; i++) cin >> arr[i];

    if (B <= C) {
        ll ans = 0;
        for (int i = 0; i < N; i++) ans += arr[i] * B;
        cout << ans;
        return;
    }

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i + 1] > arr[i + 2]) {
            ll m = min(arr[i], arr[i + 1] - arr[i + 2]);
            ans += (B + C) * m;
            arr[i] -= m, arr[i + 1] -= m;
            m = min({arr[i], arr[i + 1], arr[i + 2]});
            ans += (B + 2 * C) * m;
            arr[i] -= m, arr[i + 1] -= m, arr[i + 2] -= m;
            ans += arr[i] * B;
        } else {
            ll m = min({arr[i], arr[i + 1], arr[i + 2]});
            ans += (B + 2 * C) * m;
            arr[i] -= m, arr[i + 1] -= m, arr[i + 2] -= m;
            ans += arr[i] * B;
        }
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