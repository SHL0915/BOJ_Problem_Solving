#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, K;
pii arr[2005];
vector<pii> v[2005];
int trans[2005][(1 << 12)];
ll dp[2001][(1 << 12)];

ll DP(int now, int state) {
    if (now == N) return 0;
    ll &ret = dp[now][state];
    if (~ret) return ret;
    ret = 0;

    ret = max(ret, DP(now + 1, trans[now][state]));

    int k = K - __builtin_popcount(state);

    for (int i = 0; i < v[now].size(); i++) {
        if (state & (1 << i)) continue;
        ll cost = v[now][i].first * k;
        int nstate = state | (1 << i);
        ret = max(ret, cost + DP(now + 1, trans[now][nstate]));
        ret = max(ret, cost + DP(now, nstate));
    }

    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        priority_queue<pii> pq;
        for (int j = 0; j <= i; j++) {
            ll now = arr[j].second - (arr[i].first - arr[j].first);
            pq.push({now, j});
        }
        while (pq.size()) {
            auto t = pq.top();
            pq.pop();
            if (v[i].size() >= K) break;
            v[i].push_back(t);
        }
    }

    for (int i = 0; i < N; i++) {
        int sz = v[i].size(), nsz = v[i + 1].size();
        for (int j = 0; j < (1 << sz); j++) {
            int pos = nsz;
            for (int k = 0; k < nsz; k++) {
                if (v[i + 1][k].second == i + 1) pos = k;
            }

            int shifted = j << 1;
            for (int k = 0; k < nsz; k++) {
                if (k < pos) {
                    if (j & (1 << k)) trans[i][j] |= (1 << k);
                } else if (k == pos);
                else {
                    if (shifted & (1 << k)) trans[i][j] |= (1 << k);
                }
            }

            if (__builtin_popcount(j) != __builtin_popcount(trans[i][j])) {
                for (int k = nsz - 1; k >= 0; k--) {
                    if (trans[i][j] & (1 << k)) continue;
                    trans[i][j] |= (1 << k);
                    break;
                }
            }
        }
    }

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