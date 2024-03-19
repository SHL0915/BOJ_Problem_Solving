#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<pii> graph[20050];
ll dp[20050];

ll DP(int now) {
    if (now == 10081) return 0;
    ll &ret = dp[now];
    if (ret != -1) return ret;
    ret = max(ret, DP(now + 1));
    for (auto &[next, cost]: graph[now]) {
        ret = max(ret, cost + DP(next));
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < 20050; i++) graph[i].clear();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({a + b, c});
    }
    
    cout << DP(0) << '\n';
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