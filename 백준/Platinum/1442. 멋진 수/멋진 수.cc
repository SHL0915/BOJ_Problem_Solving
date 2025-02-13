#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 33;

ll L, R;
string A, B;
ll dp[35][4][4][2][2][2][2];

ll DP(int k, int zero, int one, int l, int r, int a, int b) {
    if (k == -1) return a * b;
    ll &ret = dp[k][zero][one][l][r][a][b];
    if (~ret) return ret;
    ret = 0;
    
    int nk, nzero, none, nl, nr, na, nb;
    nk = k - 1;
    nzero = min(zero + 1, 3);
    none = 0;
    nl = l;
    nr = r | (B[sz - k] == '1');
    na = a;
    nb = b | (nzero == 3);
    if (!na) nzero = 0;
    
    if (!((A[sz - k] == '1') && !l)) ret += DP(nk, nzero, none, nl, nr, na, nb);
    
    nk = k - 1;
    nzero = 0;
    none = min(one + 1, 3);
    nl = l | (A[sz - k] == '0');
    nr = r;
    na = 1;
    nb = b | (none == 3);
    if (!na) none = 0;
    
    if (!((B[sz - k] == '0') && !r)) ret += DP(nk, nzero, none, nl, nr, na, nb);
    
    return ret;
}

void solve() {
    cin >> L >> R;
    for (int i = sz; i >= 0; i--) {
        if (L & (1LL << i)) A += '1';
        else A += '0';
        if (R & (1LL << i)) B += '1';
        else B += '0';
    }
    
    memset(dp, -1, sizeof(dp));
    cout << DP(sz, 0, 0, 0, 0, 0, 0);
    
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