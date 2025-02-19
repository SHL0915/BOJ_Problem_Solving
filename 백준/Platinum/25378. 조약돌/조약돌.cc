#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[2505];
int ok[2505][2505], dp[2505];

int DP(int now) {
    if (now == 0) return 0;
    int &ret = dp[now];
    if (~ret) return ret;
    ret = 1e9;
    for (int i = 1; i <= now; i++) {
        if (ok[i][now]) ret = min(ret, DP(i - 1) + now - i);
        else ret = min(ret, DP(i - 1) + now - i + 1);
    }
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        ll val = arr[i];
        for (int j = i + 1; j <= N; j++) {
            if (flag) ok[i][j] = 0;
            else {
                if (val == arr[j]) ok[i][j] = 1;
                else if (val > arr[j]) {
                    flag = 1;
                    ok[i][j] = 0;
                } else {
                    ok[i][j] = 0;
                    val = arr[j] - val;
                }
            }
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << DP(N);
    
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