#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
string arr[505], S;
int dp[505][505];
pii pos[26];
char A[10] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
char B[9] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
char C[7] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

int dist(pii a, pii b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

void solve() {
    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> S;

    vector<string> v;
    int ans = INF;

    for (int i = 0; i < N; i++) {
        memset(dp, INF, sizeof(dp));
        dp[0][0] = 0;
        for (int j = 0; j <= S.length(); j++) {
            for (int k = 0; k <= arr[i].length(); k++) {
                if (j > 0 && k > 0)
                    dp[j][k] = min(dp[j][k], dist(pos[S[j - 1] - 'A'], pos[arr[i][k - 1] - 'A']) +
                                             dp[j - 1][k - 1]);
                if (j > 0) dp[j][k] = min(dp[j][k], 1600 + dp[j - 1][k]);
                if (k > 0) dp[j][k] = min(dp[j][k], 1600 + dp[j][k - 1]);
            }
        }

        int res = dp[S.length()][arr[i].length()];
        if (res < ans) {
            v.clear();
            v.push_back(arr[i]);
            ans = res;
        }
        else if (res == ans) v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());

    for (string a: v) cout << a << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    pos['Q' - 'A'] = {0, 0};
    for (int i = 1; i < 10; i++) {
        pos[A[i] - 'A'] = pos[A[i - 1] - 'A'];
        pos[A[i] - 'A'].first += 4;
    }

    pos['A' - 'A'] = {1, 4};
    for (int i = 1; i < 9; i++) {
        pos[B[i] - 'A'] = pos[B[i - 1] - 'A'];
        pos[B[i] - 'A'].first += 4;
    }

    pos['Z' - 'A'] = {3, 8};
    for (int i = 1; i < 7; i++) {
        pos[C[i] - 'A'] = pos[C[i - 1] - 'A'];
        pos[C[i] - 'A'].first += 4;
    }

    //cin >> t;
    while (t--) solve();
    return 0;
}