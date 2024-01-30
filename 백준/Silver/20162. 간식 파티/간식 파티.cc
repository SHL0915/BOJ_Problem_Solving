#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll dp[1005][100005];
int arr[1005];

ll DP(int now, int pre) {
    if (now == N + 1) return 0;
    ll &ret = dp[now][pre];
    if (ret != -1) return ret;
    ret = 0;
    ret = max(ret, DP(now + 1, pre));
    if (arr[now] > pre) ret = max(ret, arr[now] + DP(now + 1, arr[now]));
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << DP(1, 0);

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