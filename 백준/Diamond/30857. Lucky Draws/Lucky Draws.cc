#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
pii arr[10005];
int cost[10005][10005];
vector<int> v;
int dp[2][10005];

void dnc(int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    int idx = -1;
    dp[1][m] = 0;
    for (int i = l; i <= min(m, r); i++) {
        if (dp[1][m] < dp[0][i] + cost[i][m]) {
            dp[1][m] = dp[0][i] + cost[i][m];
            idx = i;
        }
    }
    dnc(s, m - 1, l, idx);
    dnc(m + 1, e, idx, r);
    return;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
        v.push_back(arr[i].first);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= N; i++) {
        arr[i].first = lower_bound(v.begin(), v.end(), arr[i].first) - v.begin() + 1;
        arr[i].second = upper_bound(v.begin(), v.end(), arr[i].second) - v.begin();
    }
    sort(arr + 1, arr + N + 1);
    
    for (int i = 0; i <= N; i++) {
        vector<int> cnt(N + 1, 0);
        int now = 0;
        for (int j = i; j <= N; j++) {
            if (arr[j].first > arr[i].first) cnt[arr[j].second]++, now++;
            cost[i][j] = now;
            if (arr[j].first != arr[j + 1].first) now -= cnt[arr[j].first];
        }
    }
    
    for (int i = 1; i <= N; i++) dp[1][i] = cost[0][i];
    for (int i = 2; i <= K; i++) swap(dp[0], dp[1]), dnc(1, N, 1, N);
    
    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dp[1][i]);
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