#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, T;
pii arr[100005];

void solve() {
    cin >> N >> T;
    ll max_W = 0;
    for (int i = 0; i < N; i++) cin >> arr[i].first, max_W = max(arr[i].first, max_W);
    for (int i = 0; i < N; i++) cin >> arr[i].second;

    priority_queue<pair<ll, pii>> pq;
    ll lval = max(1LL, T - max_W + 1);
    pq.push({T, {lval, 0}});

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll w = arr[i].first, v = arr[i].second;

        vector<pair<ll, pii>> upd;
        while (pq.size() && pq.top().first >= w) {
            auto t = pq.top();
            pq.pop();

            ll nval = t.second.second + v;
            ans = max(ans, nval);

            ll r = t.first, l = t.second.first;

            if (l >= w) upd.push_back({r - w, {l - w, nval}});
            else {
                if (r > w) upd.push_back({r - w, {0, nval}});
                if (l < w) upd.push_back({w - 1, {l, t.second.second}});
            }
        }

        for (auto u: upd) pq.push(u);
    }

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