#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, L;
ll arr[100005];

void solve() {
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N, greater<>());

    ll l = 0, r = N;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;

        ll a = 0;
        for (int i = 0; i < mid; i++) a += max(0LL, mid - arr[i]);

        if (a <= K * L && arr[mid - 1] >= mid - K) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
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