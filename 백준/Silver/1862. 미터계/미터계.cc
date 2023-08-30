#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int arr[15];

void solve() {
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        int now = S[i] - '0';
        if (now <= 3) arr[i] = now;
        else arr[i] = now - 1;
    }

    ll ans = 0;
    for (int i = 0; i < S.length(); i++) {
        ans *= 9;
        ans += arr[i];
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