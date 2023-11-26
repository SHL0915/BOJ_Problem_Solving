#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, P;
vector<int> tree[100005];
int A[100005], B[100005];

ll DFS(int node, int par) {
    ll ret = A[node] - B[node];

    for (int next: tree[node]) {
        if (next == par) continue;
        ret += DFS(next, node);
    }

    return min(0LL, ret);
}

void solve() {
    cin >> N >> P;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << -DFS(P, P);
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