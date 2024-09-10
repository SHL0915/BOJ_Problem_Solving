#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector<int> tree[1005];
int arr[1005], group[1005], par[1005];
vector<int> g[1005];

void init() {
    for (int i = 1; i <= N; i++) tree[i].clear(), g[i].clear();
}

void solve() {
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    init();
    
    int now = 1;
    group[1] = now, g[1].push_back(1);
    
    for (int i = 2; i <= N; i++) {
        if (arr[i] - arr[i - 1] != 1) now++;
        group[i] = now;
        g[group[i]].push_back(i);
    }
    
    int node = 1, ptr = 2;
    
    while (ptr <= group[N]) {
        for (int i: g[ptr]) tree[node].push_back(i), par[i] = node;
        ptr++;
        node++;
    }
    
    int k = -1;
    for (int i = 1; i <= N; i++) if (arr[i] == K) k = i;
    
    int ans = 0;
    int pp = par[par[k]];
    for (int next: tree[pp]) {
        if (next == par[k]) continue;
        ans += tree[next].size();
    }
    
    cout << ans << '\n';
    
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
    while (1) {
        cin >> N >> K;
        if (!N && !K) break;
        solve();
    }
    return 0;
}