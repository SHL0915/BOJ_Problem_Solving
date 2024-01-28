#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 9999991;

int N;
int arr[25];
ll table[25][25];
pii graph[25];
ll dp[25], sz[25];

ll nCr(int a, int b) {
    if (a == b || b == 0) return 1;
    ll &ret = table[a][b];
    if (ret != -1) return ret;
    ret = nCr(a - 1, b) + nCr(a - 1, b - 1);
    ret %= mod;
    return ret;
}

void make_graph(int node, int target) {
    if (target > node) {
        if (graph[node].second != 0) make_graph(graph[node].second, target);
        else graph[node].second = target;
    } else {
        if (graph[node].first != 0) make_graph(graph[node].first, target);
        else graph[node].first = target;
    }
    return;
}

ll DP(int node) {
    if (node == 0) return 1;
    ll &ret = dp[node];
    if (ret != -1) return ret;

    ll a = DP(graph[node].first), b = DP(graph[node].second);
    sz[node]++;
    sz[node] += sz[graph[node].first];
    sz[node] += sz[graph[node].second];
    ret = (a * b) % mod * nCr(sz[node] - 1, sz[graph[node].first]);
    ret %= mod;
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) graph[i] = {0, 0};

    int root = arr[0];
    for (int i = 1; i < N; i++) make_graph(root, arr[i]);

    memset(dp, -1, sizeof(dp));
    memset(sz, 0, sizeof(sz));
    cout << DP(root) << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(table, -1, sizeof(table));
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}