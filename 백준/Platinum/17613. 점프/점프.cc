#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;

map<pii, int> dp;
int X, Y;
pii range[35];

int DP(int left, int right) {
    if (left == 0) left++;
    if (dp.count({left, right})) return dp[{left, right}];
    int &ret = dp[{left, right}];
    ret = 0;
    
    for (int i = 1; i < 35; i++) {
        if (left > right) break;
        ll l = range[i].first, r = range[i].second;
        ll sub = (1LL << i) - 1;
        
        if (left >= l && left <= r) {
            ret = max(ret, i + DP(left - sub, min((ll) right, r) - sub));
            left = min((ll) right, r) + 1;
        }
    }
    
    return ret;
}

void solve() {
    cin >> X >> Y;
    cout << DP(X, Y) << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (int i = 1; i < 35; i++) range[i] = {(1LL << i) - 1, (1LL << (i + 1)) - 2};
    cin >> t;
    while (t--) solve();
    return 0;
}