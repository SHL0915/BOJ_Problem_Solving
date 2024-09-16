#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int sz = 50005;

int N;
pii arr[sz];
pii seg[2 * sz];

void update(int pos, pii v) {
    pos += sz;
    seg[pos].first += v.first, seg[pos].second += v.second;
    for (; pos > 0; pos >>= 1)
        seg[pos >> 1] = {seg[pos].first + seg[pos ^ 1].first, seg[pos].second + seg[pos ^ 1].second};
}

pii query(int l, int r) {
    r++;
    pii ret = {0, 0};
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret.first += seg[l].first, ret.second += seg[l].second, l++;
        if (r & 1) --r, ret.first += seg[r].first, ret.second += seg[r].second;
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N);

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        pii l = query(0, arr[i].second), r = query(arr[i].second + 1, sz - 1);
        ll now = arr[i].second * l.second - l.first + r.first - arr[i].second * r.second;
        ans += now * arr[i].first;
        update(arr[i].second, {arr[i].second, 1});
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