#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll in, out;

void solve() {
    ll pos = 0;
    
    ll l = 0, r = 1e12;
    ll ans = -1;
    
    
    while (l <= r) {
        ll m = (l + r) / 2;
        out = pos + m;
        cout << "? " << out << endl;
        cin >> in;
        
        if (in == m) {
            l = m + 1;
            ans = m + 1;
        } else {
            r = m - 1;
            ll nm = (l + r) / 2;
            if (nm <= in) {
                pos += m;
                ans = m - in;
                break;
            } else {
                pos += m;
                pos -= in;
                r = m - 1;
            }
        }
    }
    
    if (ans == 2) {
        cout << "? " << (ll) (1e18) - 1 << endl;
        cin >> in;
        if (in == 0) ans = 1;
        else ans = 2;
    }
    
    cout << "! " << ans << endl;
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}