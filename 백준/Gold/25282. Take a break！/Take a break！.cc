#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];
ll psum[100005];

void solve() {
    cin >> N;

    ll ans = 4 * 1e9;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1, greater<>());
    for (int i = 1; i <= N; i++) psum[i] = arr[i] + psum[i - 1];

    for (int i = max(1, N / 35); i <= N; i++) {
        ll sum = (i - 1) * 3600;
        for (int j = 1;; j++) {
            ll l = i * (j - 1), r = i * j;
            if (r >= N) {
                r = N;
                sum += (1LL << (j - 1)) * (psum[r] - psum[l]);
                break;
            } else sum += (1LL << (j - 1)) * (psum[r] - psum[l]);
        }
        ans = min(ans, sum);
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