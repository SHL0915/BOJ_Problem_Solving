#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
ll D[1005], C[1005];
ll dp[1005][1005];

ll DP(int now, int day) {
    if (now == N) return 0;
    if (day > M) return 1e15;
    ll &ret = dp[now][day];
    if (~ret) return ret;
    ret = 1e15;

    ll d = D[now + 1], c = C[day];
    ret = min(ret, DP(now, day + 1));
    ret = min(ret, d * c + DP(now + 1, day + 1));

    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> D[i];
    for (int i = 1; i <= M; i++) cin >> C[i];

    memset(dp, -1, sizeof(dp));

    cout << DP(0, 1);

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