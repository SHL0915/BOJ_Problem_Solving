#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
set<int> s;
ll dp[20][2][2];

ll DP(int now, int t1, int t2, string &num) {
    if (now == 20) return 1;
    ll &ret = dp[now][t1][t2];
    
    if (ret != -1) return ret;
    ret = 0;
    
    int a = num[now] - '0';
    
    if (t1) {
        if (t2) ret += DP(now + 1, 1, 1, num) * 2;
        else {
            if (a) {
                ret += DP(now + 1, 1, 0, num);
                ret += DP(now + 1, 1, 1, num);
            } else {
                ret += DP(now + 1, 1, 0, num);
            }
        }
    } else {
        if (t2) {
            if (a) {
                ret += DP(now + 1, 1, 1, num);
                ret += DP(now + 1, 0, 1, num);
            } else ret += DP(now + 1, 0, 1, num);
        } else {
            if (a) {
                ret += DP(now + 1, 1, 0, num);
                ret += DP(now + 1, 0, 1, num);
            } else ret += DP(now + 1, 0, 0, num);
        }
    }
    
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (s.count(i)) continue;
        memset(dp, -1, sizeof(dp));
        
        string num = "";
        for (int j = 0; j < 20; j++) {
            if ((1 << j) & i) num += '1';
            else num += '0';
        }
        reverse(num.begin(), num.end());
        
        ans += DP(0, 0, 0, num) - 2;
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