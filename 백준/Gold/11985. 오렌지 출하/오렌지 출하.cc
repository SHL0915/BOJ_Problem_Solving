#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct node {
    ll min = INF, max = -INF;
};

ll N, M, K;
ll arr[20005];
node seg[80005];
ll dp[20005][1005];

node merge(node a, node b) {
    return {min(a.min, b.min), max(a.max, b.max)};
}

void update(int pos, ll val) {
    for (seg[pos += N] = {val, val}; pos > 0; pos >>= 1) seg[pos >> 1] = merge(seg[pos], seg[pos ^ 1]);
    return;
}

node query(int l, int r) {
    r++;
    node ret = {INF, -INF};
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = merge(ret, seg[l++]);
        if (r & 1) ret = merge(ret, seg[--r]);
    }
    return ret;
}

ll cost(int now, int cnt) {
    node res = query(now - cnt + 1, now);
    return K + cnt * (res.max - res.min);
}

ll DP(int now, int cnt) {
    if (now == N + 1) {
        if (cnt == 1) return 0;
        else return cost(now - 1, cnt - 1);
    }
    ll &ret = dp[now][cnt];
    if (ret != -1) return ret;
    ret = INF;
    if (cnt < M) ret = min(ret, DP(now + 1, cnt + 1));
    ret = min(ret, cost(now, cnt) + DP(now + 1, 1));
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    
    memset(dp, -1, sizeof(dp));
    cout << DP(1, 1);
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