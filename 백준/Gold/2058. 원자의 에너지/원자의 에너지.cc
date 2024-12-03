#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int A[205], ok[1000005];
vector<int> tree[205];
int dp[205][2];

int DP(int node, int par, int t) {
    int &ret = dp[node][t];
    if (~ret) return ret;
    ret = 0;

    if (t) {
        int sum = 0;
        for (int next: tree[node]) {
            if (next == par) continue;
            sum += DP(next, node, 0);
        }
        ret = sum + A[node];
    } else {
        int sum = 0;
        for (int next: tree[node]) {
            if (next == par) continue;
            sum += max(DP(next, node, 0), DP(next, node, 1));
        }
        ret = sum;
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        ok[a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (ok[abs(A[i] - A[j])]) {
                tree[i].push_back(j);
                tree[j].push_back(i);
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << max(DP(1, 0, 0), DP(1, 0, 1));

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