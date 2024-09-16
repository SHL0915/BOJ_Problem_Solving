#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;
ll A[500005], B[500005], dp[500005][2], psum[500005];

ll DP(int now, int zero) {
    if (now == N + 1) return 0;
    ll &ret = dp[now][zero];
    if (~ret) return ret;
    ret = 0;

    ret = max(ret, -A[now] + DP(now + 1, 0));
    ret = max(ret, A[now] + DP(now + 1, 1));

    if (!zero) {
        int next = now + M - 1;
        if (next <= N) ret = max(ret, psum[next] - psum[now - 1] + B[next] + DP(next + 1, 0));
    }

    return ret;
}

void solve() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        psum[i] = psum[i - 1] + A[i];
    }

    for (int i = 1; i <= N; i++) cin >> B[i];

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