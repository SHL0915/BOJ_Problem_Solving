#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int dp[1005];

int DP(int n) {
    if (n <= 1) return 0;
    int &ret = dp[n];
    if (ret != -1) return ret;
    
    set<int> s;
    for (int i = 0; i <= n - 2; i++) {
        int nxt = DP(i) ^ DP(n - 2 - i);
        s.insert(nxt);
    }
    
    int now = 0;
    for (int a: s) {
        if (a == now) now++;
        else break;
    }
    
    ret = now;
    
    return ret;
}

void solve() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    int ans = DP(N);
    
    if (!ans) cout << 2;
    else cout << 1;
    
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