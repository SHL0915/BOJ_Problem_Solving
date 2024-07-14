#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A;

void solve() {
    cin >> A;

    ll l = 0, r = A;
    ll ans = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if ((m * (m + 1)) / 2 >= A) r = m - 1;
        else {
            ans = m;
            l = m + 1;
        }
    }

    string S = "()";
    for (int i = 0; i < ans; i++) S += ')';
    for (int i = 0; i < ans; i++) S += '(';

    A -= (ans * (ans + 1)) / 2;
    swap(S[0], S[A]);

    cout << S;

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