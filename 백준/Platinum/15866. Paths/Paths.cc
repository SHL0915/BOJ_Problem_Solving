#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int arr[300005];
vector<int> graph[300005];
ll dp[300005][(1 << 5)];

ll DP(int now, int state, int cnt) {
    ll &ret = dp[now][state];
    if (ret != -1) return ret;
    ret = (cnt > 1);
    for (int next: graph[now]) {
        if (state & (1 << arr[next])) continue;
        ret += DP(next, state | (1 << arr[next]), cnt + 1);
    }
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i], arr[i]--;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    ll ans = 0;

    for (int i = 1; i <= N; i++) ans += DP(i, (1 << arr[i]), 1);

    cout << ans;

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