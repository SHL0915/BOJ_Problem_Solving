#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;

void solve() {
    cin >> N >> M;
    int ans = 0;
    
    while (N > 1) {
        N--;
        ans++;
        if (M > 1) {
            M--;
            ans++;
        } else break;
    }
    
    cout << ans;
    
    
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