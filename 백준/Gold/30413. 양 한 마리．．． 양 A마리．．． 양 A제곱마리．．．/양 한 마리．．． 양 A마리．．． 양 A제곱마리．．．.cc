#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

ll A, B;

ll _pow(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ret % mod;
}

ll f(ll n) {
    if (n == 1) return 1;
    if (n % 2) return (f(n - 1) + _pow(A, n - 1)) % mod;
    else return ((1 + _pow(A, n / 2)) * f(n / 2)) % mod;
}

void solve() {
    cin >> A >> B;
    cout << f(B);
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