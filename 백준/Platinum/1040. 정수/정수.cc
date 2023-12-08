#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
const ll INF = 1e19;

ll K;
string N;
ll dp[20][11][(1 << 10)][2][20];
ll p[20];

ll DP(int now, int k, int state, int mode, int len) {
    if (k > K) return INF;
    if (now == len) {
        if (k == K) return 0;
        else return INF;
    }
    ll &ret = dp[now][k][state][mode][len];
    if (ret != -1) return ret;
    ret = INF;
    
    for (int i = 0; i < 10; i++) {
        if (now == 0 && i == 0) continue;
        if (len == N.length()) {
            if (mode == 0 && i < (N[now] - '0')) continue;
            int nmode = i > (N[now] - '0');
            ret = min(ret, i * p[len - now - 1] +
                           DP(now + 1, k + ((state & (1 << i)) == 0), state | (1 << i), mode | nmode, len));
        } else {
            int nmode = 1;
            ret = min(ret, i * p[len - now - 1] +
                           DP(now + 1, k + ((state & (1 << i)) == 0), state | (1 << i), mode | nmode, len));
        }
    }
    
    return ret;
}

void solve() {
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    int len = max((ll) N.length(), K);
    cout << (ll)(min(DP(0, 0, 0, 0, len), DP(0, 0, 0, 0, len + 1)));
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    p[0] = 1;
    for (int i = 1; i < 20; i++) p[i] = p[i - 1] * 10;
    //cin >> t;
    while (t--) solve();
    return 0;
}