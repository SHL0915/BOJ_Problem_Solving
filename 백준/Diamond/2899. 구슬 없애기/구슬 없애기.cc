#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e8;

int N, K;
int arr[105];
int dp[105][105][10];

int DP(int now, int e, int k) {
    if (now > e) return 0;
    if (now == e) return K - k;
    int &ret = dp[now][e][k];
    if (ret != -1) return ret;
    ret = INF;
    if (k < K) ret = min(ret, 1 + DP(now, e, k + 1));
    ret = min(ret, K - k + DP(now + 1, e, 1));
    for (int i = now + 1; i <= e; i++) {
        if (arr[i] == arr[now]) ret = min(ret, DP(i, e, min(K, k + 1)) + DP(now + 1, i - 1, 1));
    }
    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << DP(0, N - 1, 1);
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