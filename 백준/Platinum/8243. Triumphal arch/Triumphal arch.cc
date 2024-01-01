#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> tree[300005];
int ch[300005];

int DFS(int node, int par, int k) {
    int ret = k - ch[node];
    for (int next: tree[node]) {
        if (next == par) continue;
        ret += DFS(next, node, k);
    }

    return min(0, ret);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) ch[i] = tree[i].size() - (i != 1);

    int l = 0, r = N;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (DFS(1, 1, mid) >= 0) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

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