#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[105];

void solve() {
    cin >> N;
    ll tot = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second, tot += (arr[i].first * arr[i].second);

    if (tot % 2) {
        cout << 0 << '\n';
        return;
    }

    vector <int> dp(tot + 5, 0);
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = tot; j >= 0; j--) {
            if (!dp[j]) continue;
            for (int k = 1; k <= arr[i].second; k++) {
                if (j + arr[i].first * k > 100000) break;
                dp[j + arr[i].first * k] = 1;
            }
        }
        if (dp[tot / 2]) {
            cout << 1 << '\n';
            return;
        }
    }

    if (!dp[tot / 2]) cout << 0 << '\n';
    else cout << 1 << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 3;
    //cin >> t;
    while (t--) solve();
    return 0;
}