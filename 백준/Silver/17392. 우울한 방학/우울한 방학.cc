#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;
ll arr[1005];

void solve() {
    cin >> N >> M;
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i] + 1;
    }

    sum = M - sum;

    if (sum <= 0) cout << 0;
    else {
        ll ans = 0;
        ll a = sum / (N + 1);
        ll b = sum % (N + 1);

        for (ll i = 0; i < (N + 1 - b); i++) {
            for (ll j = 1; j <= a; j++) ans += j * j;
        }
        for (ll i = 0; i < b; i++) {
            for (ll j = 1; j <= a + 1; j++) ans += j * j;
        }

        cout << ans;
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