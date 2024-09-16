#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
string S;
bitset<2505> dp[41][41][40 * 40 + 1];

void tracing(int pos, int n, int na, int k, string &ans) {
    if (k < 0 || n < 0 || na < 0) return;
    if (!dp[pos][n][na][k]) return;
    if (pos == 0) {
        if (k != 0) return;
        reverse(ans.begin(), ans.end());
        cout << ans;
        exit(0);
    }
    if (S[pos] == '?') {
        ans += 'N';
        tracing(pos - 1, n - 1, na, k, ans);
        ans.pop_back();

        ans += 'A';
        tracing(pos - 1, n, na - n, k, ans);
        ans.pop_back();

        ans += 'C';
        tracing(pos - 1, n, na, k - na, ans);
        ans.pop_back();

        ans += 'B';
        tracing(pos - 1, n, na, k, ans);
        ans.pop_back();
    } else {
        if (S[pos] == 'N') {
            ans += S[pos];
            tracing(pos - 1, n - 1, na, k, ans);
            ans.pop_back();
        } else if (S[pos] == 'A') {
            ans += S[pos];
            tracing(pos - 1, n, na - n, k, ans);
            ans.pop_back();
        } else if (S[pos] == 'C') {
            ans += S[pos];
            tracing(pos - 1, n, na, k - na, ans);
            ans.pop_back();
        } else {
            ans += S[pos];
            tracing(pos - 1, n, na, k, ans);
            ans.pop_back();
        }
    }
}

void solve() {
    cin >> N >> K;
    cin >> S;
    S = ' ' + S;

    dp[0][0][0][0] = true;

    for (int i = 1; i < S.length(); i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N * N; k++) {
                if (S[i] == '?') {
                    if (j) dp[i][j][k] |= dp[i - 1][j - 1][k];
                    if (k >= j) dp[i][j][k] |= dp[i - 1][j][k - j];
                    dp[i][j][k] |= (dp[i - 1][j][k]) << k;
                    dp[i][j][k] |= dp[i - 1][j][k];
                } else {
                    if (S[i] == 'N') {
                        if (j) dp[i][j][k] |= dp[i - 1][j - 1][k];
                    } else if (S[i] == 'A') {
                        if (k >= j) dp[i][j][k] |= dp[i - 1][j][k - j];
                    } else if (S[i] == 'C') {
                        dp[i][j][k] |= (dp[i - 1][j][k]) << k;
                    } else dp[i][j][k] |= dp[i - 1][j][k];
                }
            }
        }
    }

    int flag = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N * N; j++) {
            if (dp[N][i][j][K]) {
                flag = 1;
                string ans = "";
                tracing(N, i, j, K, ans);
            }
        }
    }

    cout << -1;

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