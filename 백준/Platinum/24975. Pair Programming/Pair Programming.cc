#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, M;
string S, T;
vector<int> A, B;
ll dp[2005][2005];

void solve() {
    int len;
    cin >> len >> S >> T;

    A.clear(), B.clear();
    for (int i = 0; i < len; i++) {
        if (S[i] == '1') continue;
        if (S[i] == '0') A.clear();
        if (S[i] == '+') A.push_back(0);
        else A.push_back(1);
    }

    for (int i = 0; i < len; i++) {
        if (T[i] == '1') continue;
        if (T[i] == '0') B.clear();
        if (T[i] == '+') B.push_back(0);
        else B.push_back(1);
    }

    memset(dp, 0, sizeof(dp));

    N = A.size(), M = B.size();
    for (int i = 0; i <= N; i++) dp[i][0] = 1;
    for (int i = 0; i <= M; i++) dp[0][i] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;

            if (A[i - 1] == B[j - 1]) dp[i][j] = (dp[i][j] - dp[i - 1][j - 1] + mod) % mod;
        }
    }

    cout << dp[N][M] << '\n';
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