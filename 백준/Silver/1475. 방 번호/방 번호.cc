#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int cnt[10];
string S;

void solve() {
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '9') cnt[6]++;
        else cnt[S[i] - '0']++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 6) ans = max(ans, cnt[i] / 2 + cnt[i] % 2);
        else ans = max(ans, cnt[i]);
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