#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<pii> graph[105];
vector<int> v[2];
ll dp[105][105][105];

void init() {
    for (int i = 1; i <= N; i++) graph[i].clear();
    for (int i = 0; i < 2; i++) v[i].clear();
    return;
}

ll DP(int a, int b, int c) {
    if (a == v[1][0] && b == v[1][1] && c == v[1][2]) return 0;
    ll &ret = dp[a][b][c];
    if (ret != -1) return ret;
    ret = -1e17;

    int na = a, nb = b, nc = c;
    if (na == v[1][0]) na = 1e9;
    if (nb == v[1][1]) nb = 1e9;
    if (nc == v[1][2]) nc = 1e9;

    int m = min({na, nb, nc});
    if (a == m) {
        for (pii next: graph[a]) {
            if (next.first == b || next.first == c) continue;
            ret = max(ret, next.second + DP(next.first, b, c));
        }
    } else if (b == m) {
        for (pii next: graph[b]) {
            if (next.first == a || next.first == c) continue;
            ret = max(ret, next.second + DP(a, next.first, c));
        }
    } else {
        for (pii next: graph[c]) {
            if (next.first == a || next.first == b) continue;
            ret = max(ret, next.second + DP(a, b, next.first));
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M;
    init();

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    memset(dp, -1, sizeof(dp));

    cout << max(0LL, DP(v[0][0], v[0][1], v[0][2])) << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}