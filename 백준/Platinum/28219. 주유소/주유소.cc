#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, ans;
vector<int> tree[200005];

int DFS(int node, int par) {
    vector<int> child;
    for (int next: tree[node]) {
        if (next == par) continue;
        child.push_back(DFS(next, node));
    }
    sort(child.begin(), child.end(), greater<>());
    if (child.empty()) return 1;
    else {
        if (child.size() > 1) {
            int a = child[0], b = child[1];
            if (a == K || a + b >= K) {
                ans++;
                return 0;
            } else return a + 1;
        } else {
            if (child.front() == K) {
                ans++;
                return 0;
            } else return child.front() + 1;
        }
    }
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
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