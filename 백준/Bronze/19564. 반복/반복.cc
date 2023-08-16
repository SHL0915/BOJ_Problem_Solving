#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
    cin >> S;

    int ans = 1;
    for (int i = 1; i < S.length(); i++) {
        if (S[i] <= S[i - 1]) ans++;
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