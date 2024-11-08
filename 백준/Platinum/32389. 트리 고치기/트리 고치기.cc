#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector<int> tree[100005];
ll dp[100005][15], arr[100005];

ll DP(int now, int par, int k) {
    if (arr[now] > k) return 0;
    ll &ret = dp[now][k];
    if (~ret) return ret;
    ret = 0;
    
    if (arr[now]) k--;
    ret = 1;
    
    int m = tree[now].size();
    vector<int> v;
    for (int next: tree[now]) {
        if (next == par) continue;
        v.push_back(next);
    }
    vector<vector<ll>> small_dp(m + 5);
    for (int i = 0; i < m; i++) {
        small_dp[i].resize(15, -1e8);
    }
    
    if (v.size() == 0) return ret;
    
    for (int i = 0; i <= k; i++) small_dp[0][i] = DP(v[0], now, i);
    
    for (int i = 1; i < v.size(); i++) {
        for (int a = 0; a <= k; a++) {
            for (int b = 0; b <= a; b++) {
                ll cnt = DP(v[i], now, b) + small_dp[i - 1][a - b];
                small_dp[i][a] = max(small_dp[i][a], cnt);
            }
        }
    }
    
    ret = 1 + small_dp[v.size() - 1][k];
    
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        arr[a] = 1;
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << DP(1, 0, K);
    
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