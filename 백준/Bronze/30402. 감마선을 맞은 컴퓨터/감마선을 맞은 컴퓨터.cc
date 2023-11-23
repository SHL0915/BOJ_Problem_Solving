#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int ans = -1;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            char a;
            cin >> a;
            if (a == 'w') ans = 0;
            if (a == 'b') ans = 1;
            if (a == 'g') ans = 2;
        }
    }
    
    if (ans == 0) cout << "chunbae";
    else if (ans == 1) cout << "nabi";
    else cout << "yeongcheol";
    
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