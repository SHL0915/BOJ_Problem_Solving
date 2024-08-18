#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int A[5005], B[5005];
int dp[5005][5005][2];

int DP(int a, int b, int now) {
    if (a == N && b == M) return 0;
    int &ret = dp[a][b][now];
    if (~ret) return ret;
    ret = 1e9;
    if (a < N) {
        if (A[a] == now) ret = min(ret, 2 + DP(a + 1, b, now));
        else ret = min(ret, 1 + DP(a + 1, b, now ^ 1));
    }
    if (b < M) {
        if (B[b] == now % 2) ret = min(ret, 2 + DP(a, b + 1, now));
        else ret = min(ret, 1 + DP(a, b + 1, now ^ 1));
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> B[i];

    memset(dp, -1, sizeof(dp));

    cout << DP(0, 0, 0);

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