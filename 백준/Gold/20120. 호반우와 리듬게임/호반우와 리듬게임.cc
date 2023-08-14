#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
ll arr[1005];
ll dp[1005][1005][4];

ll DP(int now, int combo, int miss) {
    if (miss >= 3) return -INF;
    if (now == N) return 0;
    ll &ret = dp[now][combo][miss];
    if (ret != INF) return ret;
    ret = -INF;

    ret = max(ret, DP(now + 1, 1, miss + 1));
    ret = max(ret, arr[now] * combo + DP(now + 1, combo + 1, 0));

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    memset(dp, INF, sizeof(dp));

    cout << max(0LL, DP(0, 1, 0));
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