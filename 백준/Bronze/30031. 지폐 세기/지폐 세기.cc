#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 136) ans += 1000;
        else if (a == 142) ans += 5000;
        else if (a == 148) ans += 10000;
        else ans += 50000;
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