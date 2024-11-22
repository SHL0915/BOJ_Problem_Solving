#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 402;

int N, L, ans;
int arr[sz], t[sz];
int dp[sz][sz][sz][2];

int DP(int l, int r, int num, int pos) {
    if (l > r || num < 0 || r - l > N) return 2e9;
    if (l == N + 1 && r == N + 1) {
        if (num == 0) return 0;
        else return 2e9;
    }
    int &ret = dp[l][r][num][pos];
    if (~ret) return ret;
    ret = 2e9;
    
    int now = l;
    if (pos) now = r;
    int time = 2e9, time2 = 2e9;
    int cost;
    
    if (!pos) {
        cost = abs(arr[l + 1] - arr[now]);
        time = min(time, DP(l + 1, r, num, 0) + cost);
        if (num) time2 = min(time2, DP(l + 1, r, num - 1, 0) + cost);
        
        cost = abs(arr[r] - arr[now]);
        time = min(time, DP(l + 1, r, num, 1) + cost);
        if (num) time2 = min(time2, DP(l + 1, r, num - 1, 1) + cost);
    } else {
        cost = abs(arr[r - 1] - arr[now]);
        time = min(time, DP(l, r - 1, num, 1) + cost);
        if (num) time2 = min(time2, DP(l, r - 1, num - 1, 1) + cost);
        
        cost = abs(arr[l] - arr[now]);
        time = min(time, DP(l, r - 1, num, 0) + cost);
        if (num) time2 = min(time2, DP(l, r - 1, num - 1, 0) + cost);
    }
    
    ret = min(ret, time);
    if (num && t[now] >= time2) ret = min(ret, time2);
    
    if (ret <= 1e9 + 5) ans = max(ans, num);
    
    return ret;
}

void solve() {
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i + N + 1] = arr[i] + L;
    }
    arr[N + 1] = L;
    
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        t[i + N + 1] = t[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    for (int i = 1; i <= 2 * N + 1; i++) {
        for (int j = i; j <= 2 * N + 1; j++) {
            for (int k = 0; k <= N; k++) {
                for (int l = 0; l < 2; l++) DP(i, j, k, l);
            }
        }
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
    //int t = 1;
    //cin >> t;
    solve();
    return 0;
}