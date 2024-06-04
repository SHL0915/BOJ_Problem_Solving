#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll X, Y, A, B, C, D;

void solve() {
    cin >> X >> Y >> A >> B >> C >> D;
    
    if (A >= Y) {
        cout << "NARUTO\n";
        return;
    }
    
    ll a = (B >= C), b = (D >= A);
    if (a && b) cout << "DRAW\n";
    else {
        ll n = (Y - 1) / A + 1;
        ll m = (X - 1) / C + 1;
        if (a) {
            if (B == C) {
                if (n <= m) cout << "NARUTO\n";
                else cout << "DRAW\n";
            } else cout << "NARUTO\n";
        } else if (b) {
            if (D == A) {
                if (m < n) cout << "SASUKE\n";
                else cout << "DRAW\n";
            } else cout << "SASUKE\n";
        } else {
            if (n <= m) cout << "NARUTO\n";
            else cout << "SASUKE\n";
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
    cin >> t;
    while (t--) solve();
    return 0;
}