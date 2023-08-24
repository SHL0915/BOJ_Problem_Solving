#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, M;
string S, T;
vector<int> A, B;
ll dp[2005][2005][2];

void update(int a, int b, int k, ll v) {
    dp[a][b][k] += v;
    dp[a][b][k] %= mod;
    return;
}

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

    N = A.size(), M = B.size();

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    //dp[0][0][1] = 1;
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k < 2; k++) {
                update(i, j + 1, 1, dp[i][j][k]);
                if (k == 0) update(i + 1, j, 0, dp[i][j][k]);
                else {
                    if (i < N && j > 0 && A[i] != B[j - 1]) update(i + 1, j, 0, dp[i][j][k]);
                }
            }
        }
    }

    cout << (dp[N][M][0] + dp[N][M][1]) % mod << '\n';
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