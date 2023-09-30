#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    int lz, lo, rz, ro, mz, mo, sz;
};

int N, Q;
string S;
int arr[500005];
node seg[2000005];
int lazy[2000005];

node merge(node a, node b) {
    node ret;
    if (a.lz == a.sz) ret.lz = a.lz + b.lz;
    else ret.lz = a.lz;
    if (a.lo == a.sz) ret.lo = a.lo + b.lo;
    else ret.lo = a.lo;

    if (b.rz == b.sz) ret.rz = a.rz + b.rz;
    else ret.rz = b.rz;
    if (b.ro == b.sz) ret.ro = a.ro + b.ro;
    else ret.ro = b.ro;

    ret.mz = max({ret.rz, ret.lz, a.mz, b.mz, a.rz + b.lz});
    ret.mo = max({ret.ro, ret.lo, a.mo, b.mo, a.ro + b.lo});

    ret.sz = a.sz + b.sz;

    return ret;
}

node flip(node a) {
    node ret;
    ret.lo = a.lz;
    ret.lz = a.lo;
    ret.ro = a.rz;
    ret.rz = a.ro;
    ret.mo = a.mz;
    ret.mz = a.mo;
    ret.sz = a.sz;
    return ret;
}

void init(int n, int s, int e, int pos, int val) {
    if (pos > e || pos < s) return;
    if (s == e) {
        if (val == 0) seg[n] = {1, 0, 1, 0, 1, 0, 1};
        else seg[n] = {0, 1, 0, 1, 0, 1, 1};
        return;
    }
    int m = (s + e) / 2;
    init(n * 2, s, m, pos, val);
    init(n * 2 + 1, m + 1, e, pos, val);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return;
}

void update_lazy(int n, int s, int e) {
    if (lazy[n] != 0) {
        seg[n] = flip(seg[n]);
        if (s != e) {
            lazy[n * 2] ^= lazy[n];
            lazy[n * 2 + 1] ^= lazy[n];
        }
        lazy[n] = 0;
    }
    return;
}


void update(int n, int s, int e, int l, int r, int val) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        lazy[n] ^= val;
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, l, r, val);
    update(n * 2 + 1, m + 1, e, l, r, val);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return;
}

node query(int n, int s, int e, int l, int r) {
    update_lazy(n, s, e);
    if (l > e || r < s) return {0, 0, 0, 0, 0, 0, 0};
    if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return merge(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

void solve() {
    cin >> N >> Q;
    cin >> S;
    for (int i = 1; i <= N; i++) {
        arr[i] = S[i - 1] - '0';
        init(1, 1, N, i, arr[i]);
    }

    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) update(1, 1, N, b, c, 1);
        else {
            node q = query(1, 1, N, b, c);
            cout << max(q.mo, q.mz) << '\n';
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