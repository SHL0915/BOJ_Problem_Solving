#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int psum[601][601];
int dp[601][601][61];
vector<int> ans;

int cost(int a, int b, int c, int d) {
    return psum[d][c] - psum[d][a - 1] - psum[b - 1][c] + psum[b - 1][a - 1];
}

int DP(int now, int prev, int k) {
    if (k > K) return -2e9;
    if (now == N + 1) {
        if (k == K) return 0;
        else return -2e9;
    }
    int &ret = dp[now][prev][k];
    if (ret != -1) return ret;
    ret = 0;
    
    int a = DP(now + 1, prev, k);
    int b = cost(now + 1, prev + 1, N, now) + DP(now + 1, now, k + 1);
    ret = max(a, b);
    
    return ret;
}

void find_ans(int now, int prev, int k) {
    if (now == N + 1) return;
    int a = DP(now + 1, prev, k);
    int b = cost(now + 1, prev + 1, N, now) + DP(now + 1, now, k + 1);
    if (b >= a) {
        ans.push_back(now);
        find_ans(now + 1, now, k + 1);
    } else find_ans(now + 1, prev, k);
    return;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) cin >> psum[i][j];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
    
    memset(dp, -1, sizeof(dp));
    DP(1, 0, 0);
    find_ans(1, 0, 0);
    
    for (int a: ans) cout << a << " ";
    
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