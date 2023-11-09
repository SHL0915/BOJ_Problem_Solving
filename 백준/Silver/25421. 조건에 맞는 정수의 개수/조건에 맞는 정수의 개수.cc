#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 987654321;

int N;
ll dp[100005][10];

ll DP(int now, int val) {
    if (now == N) return 1;
    ll &ret = dp[now][val];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int i = -2; i <= 2; i++) {
        int nxt = val + i;
        if (nxt > 0 && nxt < 10) ret = (ret + DP(now + 1, nxt)) % mod;
    }
    
    return ret;
}

void solve() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 1; i < 10; i++) ans = (ans + DP(1, i)) % mod;
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