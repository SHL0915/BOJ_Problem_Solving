#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S, A, B;
int dp[3005][3005];

int DP(int a, int b) {
    if (a == A.length() || b == B.length()) return 0;
    int &ret = dp[a][b];
    if (~ret) return ret;
    ret = 0;
    ret = max(ret, DP(a + 1, b));
    ret = max(ret, DP(a + 1, b + 1));
    ret = max(ret, DP(a, b + 1));
    if (A[a] == B[b]) ret = max(ret, 1 + DP(a + 1, b + 1));
    return ret;
}

void solve() {
    cin >> S;
    
    memset(dp, -1, sizeof(dp));
    
    int m = S.length() / 2;
    for (int i = 0; i < m; i++) A += S[i];
    for (int i = m; i < S.length(); i++) B += S[i];
    
    int ans = min(m, (int) S.length() - m) - DP(0, 0);
    
    memset(dp, -1, sizeof(dp));
    A += B[0];
    B = "";
    m++;
    for (int i = m; i < S.length(); i++) B += S[i];
    
    ans = max(ans, min(m, (int) S.length() - m) - DP(0, 0));
    
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