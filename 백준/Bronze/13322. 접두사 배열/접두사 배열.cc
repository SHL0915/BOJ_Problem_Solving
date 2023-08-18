#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
    cin >> S;
    for (int i = 0; i < S.length(); i++) cout << i << '\n';
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