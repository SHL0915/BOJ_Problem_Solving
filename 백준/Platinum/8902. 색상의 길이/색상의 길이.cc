#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
string A, B;
int sz[26];
int s_idx[26][2], e_idx[26][2];
int dp[5005][5005];

int DP(int a, int b) {
    if (a == N && b == M) return 0;
    int &ret = dp[a][b];
    if (ret != INF) return ret;

    int now_a = A[a] - 'A', now_b = B[b] - 'A', cost = a + b;

    if (a < N) {
        if (a == s_idx[now_a][0] && a == e_idx[now_a][0]) {
            if (sz[now_a] == 1) ret = min(ret, DP(a + 1, b));
            else {
                if (b <= s_idx[now_a][1]) ret = min(ret, -cost + DP(a + 1, b));
                else if (b > e_idx[now_a][1]) ret = min(ret, cost + DP(a + 1, b));
                else ret = min(ret, DP(a + 1, b));
            }
        } else if (a == s_idx[now_a][0]) {
            if (b <= s_idx[now_a][1]) ret = min(ret, -cost + DP(a + 1, b));
            else ret = min(ret, DP(a + 1, b));
        } else if (a == e_idx[now_a][0]) {
            if (b > e_idx[now_a][1]) ret = min(ret, cost + DP(a + 1, b));
            else ret = min(ret, DP(a + 1, b));
        } else ret = min(ret, DP(a + 1, b));
    }

    if (b < M) {
        if (b == s_idx[now_b][1] && b == e_idx[now_b][1]) {
            if (sz[now_b] == 1) ret = min(ret, DP(a, b + 1));
            else {
                if (a <= s_idx[now_b][0]) ret = min(ret, -cost + DP(a, b + 1));
                else if (a > e_idx[now_b][0]) ret = min(ret, cost + DP(a, b + 1));
                else ret = min(ret, DP(a, b + 1));
            }
        } else if (b == s_idx[now_b][1]) {
            if (a <= s_idx[now_b][0]) ret = min(ret, -cost + DP(a, b + 1));
            else ret = min(ret, DP(a, b + 1));
        } else if (b == e_idx[now_b][1]) {
            if (a > e_idx[now_b][0]) ret = min(ret, cost + DP(a, b + 1));
            else ret = min(ret, DP(a, b + 1));
        } else ret = min(ret, DP(a, b + 1));
    }

    return ret;
}

void solve() {
    cin >> A >> B;
    N = A.length(), M = B.length();

    memset(s_idx, INF, sizeof(s_idx));
    memset(e_idx, -INF, sizeof(e_idx));
    memset(sz, 0, sizeof(sz));

    for (int i = 0; i < A.length(); i++) {
        int now = A[i] - 'A';
        s_idx[now][0] = min(s_idx[now][0], i);
        e_idx[now][0] = max(e_idx[now][0], i);
        sz[now]++;
    }

    for (int i = 0; i < B.length(); i++) {
        int now = B[i] - 'A';
        s_idx[now][1] = min(s_idx[now][1], i);
        e_idx[now][1] = max(e_idx[now][1], i);
        sz[now]++;
    }

    memset(dp, INF, sizeof(dp));
    cout << DP(0, 0) << '\n';

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