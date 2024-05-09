#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, D;

void solve() {
    cin >> N >> D;
    
    __int128 now = 1;
    for (int i = 0; i <= 61; i++) {
        if (now >= N) {
            cout << i << '\n';
            break;
        }
        now *= (D + 1);
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