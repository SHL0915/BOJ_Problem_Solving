#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A, B;

ll f(ll k) {
    if (k == 1) return 1;
    else if (k == 0) return 0;
    
    ll msb = -1;
    for (int i = 0; i <= 60; i++) if (k & (1LL << i)) msb = i;
    
    return (1LL << (msb - 1)) * msb + f(k - (1LL << msb)) + (k - (1LL << msb)) + 1;
}

void solve() {
    cin >> A >> B;
    
    cout << f(B) - f(A - 1);
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