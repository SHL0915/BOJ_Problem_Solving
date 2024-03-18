#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[3];
int A, B;
int dp[505][505][2];

int DP(int a, int b, int t) {
    int &ret = dp[a][b][t];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = 0; i < 3; i++) {
        if (a >= arr[i]) ret |= !DP(a - arr[i], b, t ^ 1);
        if (b >= arr[i]) ret |= !DP(a, b - arr[i], t ^ 1);
    }
    
    return ret;
}

void solve() {
    cin >> A >> B;
    int ans = DP(A, B, 0);
    
    if (ans) cout << "A\n";
    else cout << "B\n";
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 5;
    for (int i = 0; i < 3; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    //cin >> t;
    while (t--) solve();
    return 0;
}