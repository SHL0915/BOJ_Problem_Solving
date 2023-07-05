#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll M, A, C, X0, N, G;

__int128 f(__int128 a);

__int128 pow_a(__int128 a, __int128 n);

void solve() {
    cin >> M >> A >> C >> X0 >> N >> G;
    A %= M;
    C %= M;
    X0 %= M;

    __int128 p = (pow_a(A, N) * X0) % M;
    __int128 val = f(N - 1) % M;
    val *= C;
    val %= M;
    __int128 ans = (p + val) % M;
    ans %= G;
    cout << (ll) ans;
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

__int128 f(__int128 a) {
    if (a == 0) return 1;
    __int128 ret, x;

    if (a % 2) x = (a + 1) / 2;
    else x = a / 2;

    if (a % 2) ret = (f(x - 1) * ((pow_a(A, x) + 1) % M)) % M;
    else ret = ((f(x - 1) * ((pow_a(A, x) + 1) % M)) % M + pow_a(A, 2 * x)) % M;

    return ret;
}

__int128 pow_a(__int128 a, __int128 n) {
    __int128 ret = 1;
    __int128 mul = a;
    while (n) {
        if (n % 2) ret = (ret * mul) % M;
        mul = (mul * mul) % M;
        n /= 2;
    }

    return ret % M;
}