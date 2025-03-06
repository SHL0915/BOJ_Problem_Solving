#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;

    ll f = 0, s = 0;

    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        f = max(f, a);
        s = max(s, b);
    }

    cout << f * s;

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