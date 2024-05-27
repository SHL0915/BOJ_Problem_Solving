#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string arr[3005];
int chk[3005][3005][2];

int DP(int now, int t, vector<pii> &v, vector<vector<int>> &dp) {
    if (now == dp.size()) return 0;
    int &ret = dp[now][t];
    if (ret != -1) return ret;
    ret = 0;
    int y = v[now].first, x = v[now].second;
    ret = max(ret, DP(now + 1, 0, v, dp));
    if (t == 0) {
        if (chk[y][x][0]) ret = max(ret, 1 + DP(now + 1, 1, v, dp));
        if (chk[y][x][1]) ret = max(ret, 1 + DP(now + 1, 2, v, dp));
    } else if (t == 1) {
        if (chk[y][x][0]) ret = max(ret, 1 + DP(now + 1, 1, v, dp));
    } else {
        if (chk[y][x][1]) ret = max(ret, 1 + DP(now + 1, 2, v, dp));
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] != 'G') continue;
            if (i && i < N - 1 && arr[i - 1][j] == 'R' && arr[i + 1][j] == 'W') chk[i][j][0] = 1;
            if (j && j < M - 1 && arr[i][j - 1] == 'R' && arr[i][j + 1] == 'W') chk[i][j][1] = 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N + M - 1; i++) {
        vector<pii> v;
        pii now;
        if (i < N) now = {i, 0};
        else now = {N - 1, i - N + 1};
        while (now.first >= 0 && now.second < M) {
            v.push_back(now);
            now.first--;
            now.second++;
        }
        vector<vector<int>> dp(v.size());
        for (int j = 0; j < dp.size(); j++) dp[j].resize(3, -1);
        ans += DP(0, 0, v, dp);
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