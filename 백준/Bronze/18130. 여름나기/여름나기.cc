#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, Q;

void solve() {
    cin >> N >> Q;

    vector<pii> v;

    for (int i = 1; i <= N; i++) {
        ll P, K, C;
        cin >> P >> K >> C;
        ll a = (Q - 1) / K;
        v.push_back({P + C * (a * (a + 1) / 2), i});
    }

    sort(v.begin(), v.end());

    cout << v[0].second << " " << v[0].first;

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