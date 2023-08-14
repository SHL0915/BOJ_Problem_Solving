#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
pair<pii, int> arr[105];
ll dp[10005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    sort(arr, arr + M, [&](pair<pii, int> a, pair<pii, int> b) {
        return a.first.second < b.first.second;
    });

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < M; i++) {
        for (int j = N; j >= 0; j--) {
            int k = min(N - j, arr[i].first.first);
            dp[j + k] = min(dp[j + k], dp[j] + arr[i].first.second * k + arr[i].second);
        }
    }

    cout << dp[N] << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}