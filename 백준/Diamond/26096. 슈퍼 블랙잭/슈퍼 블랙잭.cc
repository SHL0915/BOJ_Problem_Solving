#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int D, S, E;
int arr[105];
double dp[10005];

bool check(double x) {
    for (int i = 0; i <= S; i++) dp[i] = 1e18;
    dp[0] = 0;

    for (int i = 1; i <= S; i++) {
        for (int j = 0; j < D; j++) {
            int l = i - arr[j];
            if (l <= 0) {
                int k = max(0, -(E - S) - l);
                double now = (dp[i - 1] + k * x) / arr[j] + 1;
                dp[i] = min(dp[i], now);
            } else {
                double now = (dp[i - 1] - dp[i - arr[j] - 1]) / arr[j] + 1;
                dp[i] = min(dp[i], now);
            }
        }
        dp[i] += dp[i - 1];
    }

    double res = dp[S] - dp[S - 1];

    if (res > x) return false;
    else return true;
}

void solve() {
    cin >> D;
    for (int i = 0; i < D; i++) cin >> arr[i];
    cin >> S >> E;

    double l = 0, r = 1e15;
    int cnt = 100;
    while (cnt--) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << (l + r) / 2;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cout << fixed;
    cout.precision(9);
    //cin >> t;
    while (t--) solve();
    return 0;
}