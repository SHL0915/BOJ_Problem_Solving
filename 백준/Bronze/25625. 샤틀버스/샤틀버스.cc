#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int X, Y;

void solve() {
    cin >> X >> Y;
    if (Y < X) cout << X + Y;
    else cout << Y - X;
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