#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
vector<int> idx[105];
int dp[100005][205];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int now = arr[i];
        for (int j = 0; j <= 100; j++) {
            if (idx[j].size() == 0) continue;
            int d = now - j + 100;
            int jj = idx[j].back();
            dp[i][d] = max(dp[i][d], dp[jj][d] + 1);
            ans = max(ans, dp[i][d]);
        }
        idx[now].push_back(i);
    }
    
    cout << ans + 1;
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