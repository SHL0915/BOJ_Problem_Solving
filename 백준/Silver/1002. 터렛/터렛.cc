#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll sqrdist(pii a, pii b);

void solve() {
    pii a, b;
    ll r1, r2;
    cin >> a.first >> a.second >> r1;
    cin >> b.first >> b.second >> r2;
    
    if (a == b && r1 == r2) {
        if (r1 == 0) cout << 1 << '\n';
        else cout << "-1\n";
        return;
    }
    
    ll d = sqrdist(a, b);
    if (d <= max(r1 * r1, r2 * r2)) {
        ll v = abs(r1 - r2) * abs(r1 - r2);
        if (v > d) cout << 0 << '\n';
        else if (v == d) cout << 1 << '\n';
        else cout << 2 << '\n';
    } else {
        ll v = (r1 + r2) * (r1 + r2);
        if (v > d) cout << 2 << '\n';
        else if (v == d) cout << 1 << '\n';
        else cout << 0 << '\n';
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
    cin >> t;
    while (t--) solve();
    return 0;
}

ll sqrdist(pii a, pii b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}