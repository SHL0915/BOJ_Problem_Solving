#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, D, ans;
vector<int> graph[100005];
int dp[100005];

void tree_dp(int node, int par) {
    for (int next: graph[node]) {
        if (next == par) continue;
        tree_dp(next, node);
        dp[node] = max(dp[node], dp[next] + 1);
    }
    return;
}

void DFS(int node, int par) {
    for (int next: graph[node]) {
        if (next == par) continue;
        if (dp[next] >= D) {
            ans += 2;
            DFS(next, node);
        }
    }

    return;
}

void solve() {
    cin >> N >> S >> D;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    tree_dp(S, S);
    DFS(S, S);

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