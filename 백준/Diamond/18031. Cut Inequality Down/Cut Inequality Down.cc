#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, L, U, Q;
ll arr[100005], psum[100005];
int table[200005][21];
ll min_seg[200005], max_seg[200005];

void min_upd(int pos, ll v) {
    for (min_seg[pos += N] = v; pos > 0; pos >>= 1) min_seg[pos >> 1] = min(min_seg[pos], min_seg[pos ^ 1]);
}

void max_upd(int pos, ll v) {
    for (max_seg[pos += N] = v; pos > 0; pos >>= 1) max_seg[pos >> 1] = max(max_seg[pos], max_seg[pos ^ 1]);
}

ll min_q(int l, int r) {
    r++;
    ll ret = 1e18;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, min_seg[l++]);
        if (r & 1) ret = min(ret, min_seg[--r]);
    }
    return ret;
}

ll max_q(int l, int r) {
    r++;
    ll ret = -1e18;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, max_seg[l++]);
        if (r & 1) ret = max(ret, max_seg[--r]);
    }
    return ret;
}

int _find(int idx, ll v, int t) {
    int l = idx + 1, r = N, ok = -1;
    if (t) {
        while (l <= r) {
            int m = (l + r) / 2;
            ll q = max_q(idx + 1, m) - psum[idx];
            if (q >= v) r = m - 1, ok = m;
            else l = m + 1;
        }
    } else {
        while (l <= r) {
            int m = (l + r) / 2;
            ll q = min_q(idx + 1, m) - psum[idx];
            if (q <= v) r = m - 1, ok = m;
            else l = m + 1;
        }
    }
    if (ok == -1) return N + 1;
    else return ok;
}

void solve() {
    cin >> N >> L >> U;
    for (int i = 1; i <= N; i++) cin >> arr[i], psum[i] = psum[i - 1] + arr[i];
    
    for (int i = 1; i <= N; i++) max_upd(i, psum[i]), min_upd(i, psum[i]);
    
    for (int i = 1; i <= 2 * N; i++) {
        if (i % 2) {
            int a = _find((i + 1) / 2, 0, 0), b = _find((i + 1) / 2, U - L, 1);
            if (a < b) table[i][0] = a * 2 - 1;
            else table[i][0] = b * 2;
        } else {
            int a = _find((i + 1) / 2, L - U, 0), b = _find((i + 1) / 2, 0, 1);
            if (a < b) table[i][0] = a * 2 - 1;
            else table[i][0] = b * 2;
        }
    }
    
    table[2 * N + 1][0] = table[2 * N + 2][0] = 2 * N + 2;
    
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 2 * N + 2; j++) table[j][i] = table[table[j][i - 1]][i - 1];
    }
    
    cin >> Q;
    while (Q--) {
        ll B, E, X;
        cin >> B >> E >> X;
        
        int l = B, r = E, mok = E + 1, Mok = E + 1;
        while (l <= r) {
            int m = (l + r) / 2;
            ll q = max_q(l, m) - psum[B - 1];
            if (q >= U - X) r = m - 1, Mok = m;
            else l = m + 1;
        }
        
        l = B, r = E;
        while (l <= r) {
            int m = (l + r) / 2;
            ll q = min_q(l, m) - psum[B - 1];
            if (q <= L - X) r = m - 1, mok = m;
            else l = m + 1;
        }
        
        if (Mok == mok) {
            cout << X + psum[E] - psum[B - 1] << '\n';
            continue;
        }
        
        if (Mok < mok) {
            int idx = Mok * 2;
            
            for (int i = 20; i >= 0; i--) {
                if ((table[idx][i] + 1) / 2 <= E) idx = table[idx][i];
            }
            
            ll v;
            if (idx % 2) v = L;
            else v = U;
            
            idx = (idx + 1) / 2;
            
            cout << v + psum[E] - psum[idx] << '\n';
        } else {
            int idx = mok * 2 - 1;
            
            for (int i = 20; i >= 0; i--) {
                if ((table[idx][i] + 1) / 2 <= E) idx = table[idx][i];
            }
            
            ll v;
            if (idx % 2) v = L;
            else v = U;
            
            idx = (idx + 1) / 2;
            
            cout << v + psum[E] - psum[idx] << '\n';
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