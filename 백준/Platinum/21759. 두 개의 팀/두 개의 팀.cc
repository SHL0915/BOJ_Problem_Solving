#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
ll ans = -INF;
vector<int> tree[200005];
ll arr[200005], dp[200005][3];

void DFS(int node) {
    dp[node][0] = arr[node];
    dp[node][1] = -INF;
    dp[node][2] = -INF;

    priority_queue<ll> pq;

    for (int next: tree[node]) {
        DFS(next);
        if (dp[next][0] > 0) {
            dp[node][0] += dp[next][0];
            dp[node][1] = max(dp[node][1], dp[next][1]);
        } else dp[node][1] = max(dp[node][1], dp[next][2]);
        dp[node][2] = max(dp[node][2], dp[next][2]);
        pq.push(dp[next][2]);
    }

    dp[node][2] = max(dp[node][2], dp[node][0]);
    ans = max(ans, dp[node][0] + dp[node][1]);

    while (pq.size()) {
        ll t = pq.top();
        pq.pop();
        if (pq.size()) ans = max(ans, t + pq.top());
        return;
    }

    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int p;
        cin >> p;
        if (p != -1) tree[p].push_back(i);
    }

    DFS(1);

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