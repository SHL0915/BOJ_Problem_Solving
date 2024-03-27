#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, Q;
pair<ll, pii> arr[100005];
ll v[200005], rev[100005], seg[800005], lazy[800005], sum_seg[800005];

void update_lazy(int n, int s, int e) {
    if (lazy[n] != 0) {
        seg[n] += lazy[n];
        if (s != e) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
    return;
}

void update(int n, int s, int e, int l, int r, ll v) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        lazy[n] += v;
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, l, r, v);
    update(n * 2 + 1, m + 1, e, l, r, v);
    seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
    return;
}

ll query(int n, int s, int e, int l, int r) {
    update_lazy(n, s, e);
    if (l > e || r < s) return 0x3f3f3f3f3f3f3f3fLL;
    if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return min(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

void upd(int pos, ll v) {
    for (sum_seg[pos += 2 * N] = v; pos > 0; pos >>= 1) sum_seg[pos >> 1] = sum_seg[pos] + sum_seg[pos ^ 1];
    return;
}

ll qq(int l, int r) {
    r++;
    ll ret = 0;
    for (l += 2 * N, r += 2 * N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += sum_seg[l++];
        if (r & 1) ret += sum_seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
        arr[i].second.first *= -1;
    }
    
    vector<int> turn(N + 1);
    iota(turn.begin(), turn.end(), 0);
    sort(turn.begin(), turn.end(), [&](int a, int b) {
        if (arr[a].first == arr[b].first) return a < b;
        else return arr[a].first < arr[b].first;
    });
    for (int i = 1; i <= N; i++) rev[turn[i]] = i;
    for (int i = 1; i <= N; i++) {
        ll idx = rev[i];
        ll a = arr[i].second.first, b = arr[i].second.second;
        update(1, 0, 2 * N, idx * 2 - 1, 2 * N, a);
        update(1, 0, 2 * N, idx * 2, 2 * N, b);
        upd(idx * 2 - 1, a);
        upd(idx * 2, b);
    }
    
    cin >> Q;
    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c, d;
            cin >> b >> c >> d;
            int l = 1, r = N;
            int lans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (arr[turn[m]].first >= c) {
                    lans = m;
                    r = m - 1;
                } else l = m + 1;
            }
            
            l = 1, r = N;
            int rans = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (arr[turn[m]].first <= d) {
                    rans = m;
                    l = m + 1;
                } else r = m - 1;
            }
            
            if (lans > rans) {
                cout << -1 << '\n';
                continue;
            }
            
            ll q = query(1, 0, 2 * N, lans * 2 - 1, rans * 2) - query(1, 0, 2 * N, lans * 2 - 2, lans * 2 - 2);
            
            if (b + q < 0) cout << -1 << '\n';
            else cout << 1 << " " << b + qq(lans * 2 - 1, rans * 2) << '\n';
        } else if (a == 2) {
            int b, c;
            cin >> b >> c;
            ll now = arr[b].second.first;
            update(1, 0, 2 * N, rev[b] * 2 - 1, 2 * N, -now);
            arr[b].second.first = -c;
            now = arr[b].second.first;
            update(1, 0, 2 * N, rev[b] * 2 - 1, 2 * N, now);
            upd(rev[b] * 2 - 1, now);
        } else {
            int b, c;
            cin >> b >> c;
            ll now = arr[b].second.second;
            update(1, 0, 2 * N, rev[b] * 2, 2 * N, -now);
            arr[b].second.second = c;
            now = arr[b].second.second;
            update(1, 0, 2 * N, rev[b] * 2, 2 * N, now);
            upd(rev[b] * 2, now);
        }
    }
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