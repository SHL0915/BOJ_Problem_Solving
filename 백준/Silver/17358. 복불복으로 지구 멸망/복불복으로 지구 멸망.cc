#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll mod = 1000000007;

ll N;

void solve() {
    cin >> N;
    ll ans = 1;
    for (int i = N - 1; i >= 0; i -= 2) {
        ans = (ans * i) % mod;
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