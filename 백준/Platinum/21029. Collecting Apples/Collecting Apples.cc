#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll R, C, K;
ll dp[35][35][65 * 205];
int arr[35][35];

ll DP(int r, int c, int k) {
    if (r == R && c == C && k == arr[r][c]) return 1;
    ll &ret = dp[r][c][k];
    if (~ret) return ret;
    ret = 0;
    
    if (r < R && k >= arr[r + 1][c]) ret += DP(r + 1, c, k - arr[r + 1][c]);
    if (c < C && k >= arr[r][c + 1]) ret += DP(r, c + 1, k - arr[r][c + 1]);
    
    return ret;
}

void solve() {
    cin >> R >> C >> K;
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cin >> arr[i][j];
    }
    
    memset(dp, -1, sizeof(dp));
    
    string ans;
    
    int r = 1, c = 1, k = 65 * 200;
    while (r < R || c < C) {
        if (DP(r, c, k) < K) {
            K -= DP(r, c, k);
            k--;
        } else {
            int a = k - arr[r + 1][c], b = k - arr[r][c + 1];
            if (DP(r + 1, c, a) < K) {
                K -= DP(r + 1, c, a);
                c++;
                k = b;
                ans += 'R';
            } else {
                r++;
                k = a;
                ans += 'D';
            }
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