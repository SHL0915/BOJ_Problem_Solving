#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[1000005], dp[1000005];
vector<int> sidx, eidx;

ll cal(int i, int j) {
    return (eidx[j - 1] - sidx[i - 1]) * (arr[sidx[i - 1]] + arr[eidx[j - 1]]);
}

void DNC(int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    int idx = lower_bound(eidx.begin(), eidx.end(), sidx[m - 1]) - eidx.begin();
    int opt;

    for (int i = max(l, idx); i <= r; i++) {
        if (dp[m] < cal(m, i)) {
            dp[m] = cal(m, i);
            opt = i;
        }
    }

    DNC(s, m - 1, l, opt);
    DNC(m + 1, e, opt, r);

    return;
}

void solve() {
    cin >> N;
    ll max_val = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > max_val) sidx.push_back(i);
        max_val = max(max_val, arr[i]);
    }

    max_val = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] > max_val) eidx.push_back(i);
        max_val = max(max_val, arr[i]);
    }

    sort(eidx.begin(), eidx.end());
    int S = sidx.size(), E = eidx.size();

    DNC(1, S, 1, E);

    ll ans = 0;
    for (int i = 1; i <= S; i++) ans = max(ans, dp[i]);

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