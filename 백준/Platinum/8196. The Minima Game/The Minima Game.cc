#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
ll arr[1000005], dp[1000005][2];

ll DP(int idx, int turn) {
    if (idx == N) return 0;
    ll &ret = dp[idx][turn];
    if (ret != INF) return ret;
    ret = 0;
    ret = max(ret, arr[idx] - DP(idx + 1, turn ^ 1));
    ret = max(ret, DP(idx + 1, turn));

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N, greater<>());

    memset(dp, INF, sizeof(dp));
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