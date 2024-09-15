#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll Q, W, sz;
vector<ll> pos;
vector<pii> q;
ll seg[4 * 400005], len[4 * 400005];

void update(int n, int s, int e, int l, int r, int v) {
    if (l > e || r < s) return;
    if (l <= s && e <= r) seg[n] += v;
    else {
        int m = (s + e) >> 1;
        update(n * 2, s, m, l, r, v);
        update(n * 2 + 1, m + 1, e, l, r, v);
    }
    if (seg[n]) len[n] = pos[e] - pos[s - 1];
    else if (s == e) len[n] = 0;
    else len[n] = len[n * 2] + len[n * 2 + 1];
}

ll query() {
    return len[1];
}

void solve() {
    cin >> Q >> W;

    pos.push_back(-1e9);
    pos.push_back(0);
    pos.push_back(W);

    for (int i = 0; i < Q; i++) {
        ll x, y;
        cin >> x >> y;
        q.push_back({x, y});
        ll l = max(0LL, x - y), r = min(W, x + y);
        pos.push_back(l);
        pos.push_back(r);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    sz = pos.size();

    set<pii> s;
    for (int i = 0; i < Q; i++) {
        ll x = q[i].first, y = q[i].second;
        ll l = max(0LL, x - y), r = min(W, x + y);
        int lpos = lower_bound(pos.begin(), pos.end(), l) - pos.begin(), rpos =
                lower_bound(pos.begin(), pos.end(), r) - pos.begin();
        if (s.count({x, y})) {
            s.erase({x, y});
            update(1, 0, sz - 1, lpos + 1, rpos, -1);
        } else {
            s.insert({x, y});
            update(1, 0, sz - 1, lpos + 1, rpos, 1);
        }

        ll ans = query();
        cout << (long double) ans * sqrt(2) << '\n';
    }

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(12);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}