#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii S, E;
int arr[1000005];
ll psum[1000005];
map<pii, ll> dp;

ll dist(pii a, pii b) {
    ll f = psum[a.first - 1] + a.second, s = psum[b.first - 1] + b.second;
    return abs(f - s);
}

ll DP(int y, int x) {
    if (y == E.first && x == E.second) return 0;
    if (dp.count({y, x})) return dp[{y, x}];
    ll &ret = dp[{y, x}];
    ret = 1e18;

    ret = dist({y, x}, E);
    if (y > 1) ret = min(ret, 1 + DP(y - 1, min(x, arr[y - 1] + 1)));
    if (y < N) ret = min(ret, 1 + DP(y + 1, min(x, arr[y + 1] + 1)));
    if (x == 1 && y > 1) ret = min(ret, 1 + DP(y - 1, arr[y - 1] + 1));
    if (x == arr[y] + 1 && y < N) ret = min(ret, 1 + DP(y + 1, 1));
    ret = min(ret, dist({y, x}, {y, 1}) + DP(y, 1));
    ret = min(ret, dist({y, x}, {y, arr[y] + 1}) + DP(y, arr[y] + 1));

    return ret;
}

void solve() {
    cin >> N;

    cin >> S.first >> S.second >> E.first >> E.second;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i] + 1;
    }

    cout << DP(S.first, S.second);

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