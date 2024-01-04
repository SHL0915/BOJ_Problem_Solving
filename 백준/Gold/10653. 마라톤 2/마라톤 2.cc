#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, K;
pii arr[505];
ll dp[505][505];

ll dist(pii a, pii b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return abs(dx) + abs(dy);
}

ll DP(int now, int k) {
    if (now == N - 1) {
        if (k == K) return 0;
        else return INF;
    }
    ll &ret = dp[now][k];
    if (ret != -1) return ret;
    ret = INF;
    ret = min(ret, dist(arr[now], arr[now + 1]) + DP(now + 1, k));
    
    for (int i = now + 2; i < N; i++) {
        ret = min(ret, dist(arr[now], arr[i]) + DP(i, k + (i - now - 1)));
    }
    
    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    memset(dp, -1, sizeof(dp));
    
    cout << DP(0, 0);
    
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