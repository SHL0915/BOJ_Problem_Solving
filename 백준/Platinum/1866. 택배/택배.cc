#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, A, B;
int arr[3005], psum[3005];
int dp[3005][3005];

int cost(int now, int pre) {
    int m = arr[pre] + (arr[now] - arr[pre]) / 2;
    int idx = upper_bound(arr, arr + N + 1, m) - arr - 1;
    int tot = psum[idx] - psum[pre] - arr[pre] * (idx - pre) + arr[now] * (now - idx) - (psum[now] - psum[idx]);
    return A * tot;
}

int DP(int now, int pre) {
    if (now == N + 1) return A * (psum[N] - psum[pre] - arr[pre] * (N - pre));
    int &ret = dp[now][pre];
    if (ret != -1) return ret;
    ret = INF;
    ret = min(ret, DP(now + 1, pre));
    ret = min(ret, B + cost(now, pre) + DP(now + 1, now));

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + arr[i];
    cin >> A >> B;

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