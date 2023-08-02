#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, D1, D2;

void solve() {
    cin >> K >> D1 >> D2;
    double ans = K * K;
    double a = double(D1 - D2) / 2.0;
    ans -= a * a;

    cout << ans;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}