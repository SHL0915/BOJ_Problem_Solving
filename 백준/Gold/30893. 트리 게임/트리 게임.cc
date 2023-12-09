#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, E, ans;
vector<int> tree[100005];

void DFS(int node, int par, int parity) {
    int cnt = 0;
    if (node == E) return;
    for (int next: tree[node]) {
        if (next == par) continue;
        cnt++;
        DFS(next, node, parity ^ 1);
    }
    if (parity && cnt > 1) ans = 1;
    return;
}

void solve() {
    cin >> N >> S >> E;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(S, S, 0);
    
    if (!ans) cout << "First";
    else cout << "Second";
    
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