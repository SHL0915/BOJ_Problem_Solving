#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int arr[4000005];

void solve() {
    cin >> S;
    
    string s = "#";
    
    int r = 0, p = 0;
    for (int i = 0; i < S.length(); i++) {
        s += S[i];
        s += '#';
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (i <= r) arr[i] = min(r - i, arr[2 * p - i]);
        while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < s.length() && s[i - arr[i] - 1] == s[i + arr[i] + 1]) arr[i]++;
        if (r < i + arr[i]) r = i + arr[i], p = i;
    }
    
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) ans += (arr[i] + 1) / 2;
    
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