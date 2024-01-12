#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
vector<pii> tree[300005];
ll arr[300005], sz[300005];

ll DFS(int node, int par, ll val) {
    ll ret = val;
    sz[node]++;
    for (auto &[next, cost]: tree[node]) {
        if (next == par) continue;
        ret += DFS(next, node, val + cost);
        sz[node] += sz[next];
    }
    return ret;
}

void dfs(int node, int par) {
    for (auto &[next, cost]: tree[node]) {
        if (next == par) continue;
        arr[next] = arr[node] + cost * (N - 2 * sz[next]);
        dfs(next, node);
    }
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    arr[1] = DFS(1, 1, 0);
    dfs(1, 1);

    for (int i = 1; i <= N; i++) cout << arr[i] << '\n';

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