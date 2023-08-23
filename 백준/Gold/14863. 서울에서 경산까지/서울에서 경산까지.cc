#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, K;
pair<pii, pii> arr[105];
ll dp[105][100005];

ll DP(int now, int t) {
    if (t > K) return -INF;
    if (now == N) return 0;
    ll &ret = dp[now][t];
    if (ret != -1) return ret;
    ret = -INF;

    ret = max(ret, arr[now].first.second + DP(now + 1, t + arr[now].first.first));
    ret = max(ret, arr[now].second.second + DP(now + 1, t + arr[now].second.first));

    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;

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