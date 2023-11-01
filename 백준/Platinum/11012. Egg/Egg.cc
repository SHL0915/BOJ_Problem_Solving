#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int sz = 100005;

int N, M;
pii arr[sz];
vector<pii> ins[sz], del[sz];
ll seg[2 * sz];

void update(int pos, ll val) {
    for (seg[pos += sz] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

ll query(int l, int r) {
    r++;
    ll ret = 0;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < sz; i++) {
        ins[i].clear();
        del[i].clear();
    }
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ins[a].push_back({c, d});
        del[b + 1].push_back({c, d});
    }
    
    sort(arr, arr + N);
    memset(seg, 0, sizeof(seg));
    
    ll now = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        ll x = arr[i].first, y = arr[i].second;
        while (now <= x) {
            for (pii a: ins[now]) {
                update(a.first, 1);
                update(a.second + 1, -1);
            }
            for (pii a: del[now]) {
                update(a.first, -1);
                update(a.second + 1, 1);
            }
            now++;
        }
        ans += query(0, y);
    }
    
    cout << ans << endl;
    
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