#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
ll ans;
ll arr[100005];
vector<int> tree[100005];

pii DFS(int node, int par) {
    ll sum = 0;
    ll remain = 0;
    for (int next: tree[node]) {
        if (next == par) continue;
        pii a = DFS(next, node);
        sum += a.first;
        remain = max(remain, a.second);
    }
    
    if (remain == 0) return {0, max(0LL, arr[node] - sum)};
    else {
        ans += remain;
        sum += remain;
        return {remain, max(0LL, arr[node] - sum)};
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    assert(M == N - 1);
    
    ans += DFS(1, 1).second;
    
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