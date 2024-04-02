#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
int dp[3000005];
ll fibo[55];

int DP(int k) {
    if (k == 0) return 0;
    int &ret = dp[k];
    if (ret != -1) return ret;
    
    int cnt[25] = {0};
    for (int i = 0; i <= 32; i++) {
        if (fibo[i] > k) break;
        cnt[DP(k - fibo[i])]++;
    }
    
    int now = 0;
    for (int i = 0; i < 25; i++) {
        if (cnt[i]) now++;
        else break;
    }
    
    ret = now;
    return ret;
}


void solve() {
    cin >> N;
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ans ^= DP(arr[i]);
    }
    
    if (ans) cout << "koosaga";
    else cout << "cubelover";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= 32; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    //cin >> t;
    while (t--) solve();
    return 0;
}