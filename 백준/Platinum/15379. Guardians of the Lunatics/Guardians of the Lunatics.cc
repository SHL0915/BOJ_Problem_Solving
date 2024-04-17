#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e18;

int L, G;
ll arr[8005];
ll psum[8005];
ll dp[2][8005];

inline ll cost(int l, int r) {
    return (r - l + 1) * (psum[r] - psum[l - 1]);
}

void dnc(int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    dp[1][m] = INF;
    int idx = -1;
    for (int i = l; i <= min(m, r); i++) {
        if (dp[1][m] > dp[0][i] + cost(i + 1, m)) {
            dp[1][m] = dp[0][i] + cost(i + 1, m);
            idx = i;
        }
    }
    dnc(s, m - 1, l, idx);
    dnc(m + 1, e, idx, r);
    return;
}

void solve() {
    cin >> L >> G;
    for (int i = 1; i <= L; i++) cin >> arr[i], psum[i] = psum[i - 1] + arr[i];
    
    for (int i = 1; i <= L; i++) dp[1][i] = cost(1, i);
    for (int i = 2; i <= G; i++) swap(dp[0], dp[1]), dnc(1, L, 1, L);
    
    cout << dp[1][L] << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}