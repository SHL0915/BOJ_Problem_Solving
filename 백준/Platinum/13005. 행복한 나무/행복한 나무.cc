#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
ll arr[100005];
vector<pii> tree[100005];
int cut[100005];

void DFS(int node, ll v) {
    if (v > arr[node]) cut[node] = 1;

    ll n = max(0LL, v);
    if (cut[node]) n = 1e15;

    for (auto &[next, cost]: tree[node]) DFS(next, n + cost);

    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 2; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back({i, b});
    }

    DFS(1, 0);

    int cnt = 0;
    for (int i = 1; i <= N; i++) cnt += cut[i];

    cout << cnt;

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