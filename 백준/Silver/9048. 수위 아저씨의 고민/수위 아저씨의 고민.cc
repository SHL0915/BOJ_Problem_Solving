#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int F, R, N;

void solve() {
    cin >> F >> R >> N;
    vector<ll> pos[35];
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> y >> x;
        pos[y].push_back(x);
    }

    ll ans = F * 2 + R + 1;

    for (int i = 1; i <= F; i++) {
        pos[i].push_back(0);
        pos[i].push_back(R + 1);
        sort(pos[i].begin(), pos[i].end());
        ll val = 0;
        for (int j = 1; j < pos[i].size(); j++) val = max(val, pos[i][j] - pos[i][j - 1]);
        ans += 2 * (R + 1) - 2 * val;
    }

    cout << ans << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}