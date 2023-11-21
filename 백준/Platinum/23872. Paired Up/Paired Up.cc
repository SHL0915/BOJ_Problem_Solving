#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll T, N, K;
ll arr[100005], pos[100005];
ll dp[100005][2];
ll dp2[100005][2];

ll DP(int now, int type) {
    if (now == N) {
        if (type == 0) return 0;
        else return -INF;
    }
    ll &ret = dp[now][type];
    if (ret != -1) return ret;
    ret = -INF;
    
    if (pos[now + 1] - pos[now] <= K) ret = max(ret, DP(now + 1, type ^ 1));
    else if (type == 1) ret = max(ret, DP(now + 1, 0));
    
    int nxt = upper_bound(pos, pos + N, pos[now] + K) - pos;
    int sz = nxt - now - 1;
    
    if (now > 0 && pos[now + 1] - pos[now - 1] > K) {
        if (type == 0) {
            if (pos[nxt] - pos[nxt - 1] > K) {
                if ((type ^ (sz % 2)) == 0) ret = max(ret, arr[now] + DP(nxt, 0));
            } else ret = max(ret, arr[now] + DP(nxt, type ^ (sz % 2)));
        }
    } else {
        if (pos[nxt] - pos[nxt - 1] > K) {
            if ((type ^ (sz % 2)) == 0) ret = max(ret, arr[now] + DP(nxt, 0));
        } else ret = max(ret, arr[now] + DP(nxt, type ^ (sz % 2)));
    }
    
    return ret;
}

ll DP2(int now, int type) {
    if (now == N) {
        if (type == 0) return 0;
        else return INF;
    }
    ll &ret = dp2[now][type];
    if (ret != -1) return ret;
    ret = INF;
    
    if (pos[now + 1] - pos[now] <= K) ret = min(ret, DP2(now + 1, type ^ 1));
    else if (type == 1) ret = min(ret, DP2(now + 1, 0));
    
    int nxt = upper_bound(pos, pos + N, pos[now] + K) - pos;
    int sz = nxt - now - 1;
    
    if (now > 0 && pos[now + 1] - pos[now - 1] > K) {
        if (type == 0) {
            if (pos[nxt] - pos[nxt - 1] > K) {
                if ((type ^ (sz % 2)) == 0) ret = min(ret, arr[now] + DP2(nxt, 0));
            } else ret = min(ret, arr[now] + DP2(nxt, type ^ (sz % 2)));
        }
    } else {
        if (pos[nxt] - pos[nxt - 1] > K) {
            if ((type ^ (sz % 2)) == 0) ret = min(ret, arr[now] + DP2(nxt, 0));
        } else ret = min(ret, arr[now] + DP2(nxt, type ^ (sz % 2)));
    }
    
    return ret;
}

void solve() {
    cin >> T >> N >> K;
    for (int i = 0; i < N; i++) cin >> pos[i] >> arr[i];
    pos[N] = pos[N - 1];
    
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    
    if (T == 1) cout << DP2(0, 0);
    else cout << DP(0, 0);
    
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