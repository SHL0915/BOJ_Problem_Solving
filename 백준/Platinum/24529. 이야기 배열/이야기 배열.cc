#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3fLL;

int N;
int arr[55];
pii A[55], B[55], C[55];
ll dp[55][55][55][55][4];

ll DP(int now, int a, int b, int c, int last) {
    if (now == N) return 0;

    ll &ret = dp[now][a][b][c][last];
    if (ret != -1) return ret;
    ret = -INF;

    if (a < N) ret = max(ret, DP(now, a + 1, b, c, last));
    if (b < N) ret = max(ret, DP(now, a, b + 1, c, last));
    if (c < N) ret = max(ret, DP(now, a, b, c + 1, last));

    if (last == 3) {
        if ((A[a].first <= arr[now]) && a < N) ret = max(ret, A[a].second + DP(now + 1, a + 1, b, c, 0));
        if ((B[b].first <= arr[now]) && b < N) ret = max(ret, B[b].second + DP(now + 1, a, b + 1, c, 1));
        if ((C[c].first <= arr[now]) && c < N) ret = max(ret, C[c].second + DP(now + 1, a, b, c + 1, 2));
    } else if (last == 0) {
        if ((B[b].first <= arr[now]) && b < N) ret = max(ret, B[b].second + DP(now + 1, a, b + 1, c, 1));
        if ((C[c].first <= arr[now]) && c < N) ret = max(ret, C[c].second + DP(now + 1, a, b, c + 1, 2));
    } else if (last == 1) {
        if ((A[a].first <= arr[now]) && a < N) ret = max(ret, A[a].second + DP(now + 1, a + 1, b, c, 0));
        if ((C[c].first <= arr[now]) && c < N) ret = max(ret, C[c].second + DP(now + 1, a, b, c + 1, 2));
    } else {
        if ((A[a].first <= arr[now]) && a < N) ret = max(ret, A[a].second + DP(now + 1, a + 1, b, c, 0));
        if ((B[b].first <= arr[now]) && b < N) ret = max(ret, B[b].second + DP(now + 1, a, b + 1, c, 1));
    }

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i].second >> A[i].first;
    for (int i = 0; i < N; i++) cin >> B[i].second >> B[i].first;
    for (int i = 0; i < N; i++) cin >> C[i].second >> C[i].first;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    memset(dp, -1, sizeof(dp));
    ll ans = DP(0, 0, 0, 0, 3);

    if (ans <= 0) cout << -1;
    else cout << ans;

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