#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, D, ans;
vector<int> graph[100005];

int DFS(int node, int par) {
    int ret = 0;
    for (int next: graph[node]) {
        if (next == par) continue;
        int nxt = DFS(next, node);
        if (nxt >= D) ans += 2;
        ret = max(ret, nxt + 1);
    }

    return ret;
}

void solve() {
    cin >> N >> S >> D;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

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