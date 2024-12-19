#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pair<pii, int> arr[100005];
int dp[100005][2];

int DP(int now, int t) {
    if (now == N + 1) return 0;
    int &ret = dp[now][t];
    if (~ret) return ret;
    ret = 0;
    ret = max(ret, DP(now + 1, 0));
    
    if (!t) ret = max(ret, arr[now].second + DP(now + 1, 1));
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        arr[i] = {{l, r}, w};
    }
    memset(dp, -1, sizeof(dp));
    
    cout << DP(0, 0);
    
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