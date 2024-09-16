#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> tree[100005];
ll arr[100005];

ll DFS(int node, int par) {
    ll ret = arr[node];

    for (int next: tree[node]) {
        if (next == par) continue;
        ll v = DFS(next, node);
        ret += max(0LL, v);
    }

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << DFS(0, 0);

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