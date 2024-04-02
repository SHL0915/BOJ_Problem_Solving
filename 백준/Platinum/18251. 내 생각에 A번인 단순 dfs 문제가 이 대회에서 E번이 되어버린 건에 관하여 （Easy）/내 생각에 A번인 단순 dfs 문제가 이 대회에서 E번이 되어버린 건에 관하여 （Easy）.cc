#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1e18;

int N;
ll arr[300005];
vector<ll> v;

void DFS(int node, int l, int r, int lv) {
    if (node > N) return;
    DFS(node * 2, l, r, lv + 1);
    if (lv >= l && lv <= r) v.push_back(arr[node]);
    DFS(node * 2 + 1, l, r, lv + 1);
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    ll ans = -INF;
    for (int i = 1; i <= 19; i++) {
        for (int j = i + 1; j <= 19; j++) {
            v.clear();
            DFS(1, i, j, 1);
            vector<ll> dp(v.size());
            if (v.empty()) continue;
            dp[0] = v[0];
            ans = max(ans, v[0]);
            for (int k = 1; k < v.size(); k++) {
                dp[k] = max(v[k], dp[k - 1] + v[k]);
                ans = max(ans, dp[k]);
            }
        }
    }
    
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