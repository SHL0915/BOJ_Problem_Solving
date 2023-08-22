#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, ans = INF;
vector<int> tree[200005];
int sz[200005];
multiset<int> A, B;

void tree_dp(int node, int par) {
    sz[node]++;
    for (int next: tree[node]) {
        if (next == par) continue;
        tree_dp(next, node);
        sz[node] += sz[next];
    }

    return;
}

void DFS(int node, int par) {
    auto idx = A.lower_bound((N + sz[node]) / 2);
    if (idx != A.end()) {
        int a = max({sz[node], *idx - sz[node], N - *idx});
        int b = min({sz[node], *idx - sz[node], N - *idx});
        ans = min(ans, a - b);
    }
    if (idx != A.begin()) {
        idx--;
        int a = max({sz[node], *idx - sz[node], N - *idx});
        int b = min({sz[node], *idx - sz[node], N - *idx});
        ans = min(ans, a - b);
    }

    idx = B.lower_bound((N + sz[node]) / 2);
    if (idx != B.end()) {
        int a = max({sz[node], *idx, N - *idx - sz[node]});
        int b = min({sz[node], *idx, N - *idx - sz[node]});
        ans = min(ans, a - b);
    }
    if (idx != B.begin()) {
        idx--;
        int a = max({sz[node], *idx, N - *idx - sz[node]});
        int b = min({sz[node], *idx, N - *idx - sz[node]});
        ans = min(ans, a - b);
    }

    A.insert(sz[node]);
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node);
    }
    A.erase(A.find(sz[node]));

    B.insert(sz[node]);
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    tree_dp(1, 1);
    DFS(1, 1);

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