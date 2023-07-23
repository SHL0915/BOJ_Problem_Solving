#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, T;
vector<int> tree[200005];
ll arr[200005], sz[200005], psum[200005], depth[200005];
ll dp[200005][2];

void tree_dp(int node) {
    psum[node] += arr[node];
    sz[node] = 1;
    for (int next: tree[node]) {
        tree_dp(next);
        sz[node] += sz[next];
        depth[node] = max(depth[node], depth[next] + 1);
        psum[node] += psum[next];
    }
    return;
}

void DFS(int node, int t) {
    if (t == 0) {
        for (int next: tree[node]) DFS(next, t);
        sort(tree[node].begin(), tree[node].end(), [&](int a, int b) {
            return sz[a] * psum[b] < sz[b] * psum[a];
        });
        ll sum = 1;
        for (int next: tree[node]) {
            dp[node][t] += (dp[next][t] + sum * psum[next]);
            sum += 2 * sz[next];
        }
    } else {
        for (int next: tree[node]) DFS(next, 1);

        sort(tree[node].begin(), tree[node].end(), [&](int a, int b) {
            if (depth[a] == depth[b])
                return dp[a][0] + sz[a] * 2 * psum[b] + dp[b][1] < dp[b][0] + sz[b] * 2 * psum[a] + dp[a][1];
            return depth[a] < depth[b];
        });

        if (tree[node].size()) {
            sort(tree[node].begin(), tree[node].end() - 1, [&](int a, int b) {
                return sz[a] * psum[b] < sz[b] * psum[a];
            });

            ll sum = 1;
            for (int i = 0; i < tree[node].size() - 1; i++) {
                int next = tree[node][i];
                dp[node][t] += (dp[next][0] + sum * psum[next]);
                sum += 2 * sz[next];
            }

            dp[node][t] += dp[tree[node].back()][1] + sum * psum[tree[node].back()];
        }
    }
}

void solve() {
    cin >> N >> T;
    for (int i = 2; i <= N; i++) {
        int a;
        cin >> a >> arr[i];
        tree[a].push_back(i);
    }

    tree_dp(1);

    DFS(1, 0);
    DFS(1, 1);

    if (T) cout << (N - 1) * 2 - depth[1] << " ";
    else cout << (N - 1) * 2 << " ";

    cout << dp[1][T];
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