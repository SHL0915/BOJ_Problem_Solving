#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

ll N, D, S, A, B;

void update(int pos, ll v, vector<ll> &seg) {
    for (seg[pos += N + 5] += v; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

ll query(int l, int r, vector<ll> &seg) {
    r++;
    ll ret = 0;
    for (l += N + 5, r += N + 5; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N >> D >> S >> A >> B;
    
    ll ans = 0, ptr = 0;
    vector<ll> seg(2 * N + 505, 0);
    
    for (int i = 1; i <= D; i++) {
        ll Ci = S % N + 1;
        S = (S * A + B) % mod;
        ll Ki = S % N + 1;
        S = (S * A + B) % mod;
        
        int e = ptr + Ci - 1;
        if (e < N) {
            update(ptr, i, seg);
            update(e + 1, -i, seg);
        } else {
            update(ptr, i, seg);
            update(N, -i, seg);
            e = (Ci - N + ptr - 1);
            update(0, i, seg);
            update(e + 1, -i, seg);
        }
        
        ptr += Ci, ptr %= N;
        ans += query(0, (ptr + Ki - 1) % N, seg);
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