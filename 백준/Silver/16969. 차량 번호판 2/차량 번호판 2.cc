#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 9;

string S;
int val[2] = {26, 10};

void solve() {
    cin >> S;
    ll ans = val[S[0] - 'c'];
    
    for (int i = 1; i < S.length(); i++) {
        ll v = val[S[i] - 'c'];
        if (S[i] == S[i - 1]) v--;
        ans *= v;
        ans %= mod;
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