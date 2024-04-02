#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

vector<int> manacher(string s) {
    vector<int> ret(s.length());
    
    int r = 0, p = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i <= r) ret[i] = min(r - i, ret[2 * p - i]);
        while (i - ret[i] - 1 >= 0 && i + ret[i] + 1 < s.length() && s[i - ret[i] - 1] == s[i + ret[i] + 1]) ret[i]++;
        if (i + ret[i] > r) r = i + ret[i], p = i;
    }
    
    return ret;
}

void solve() {
    cin >> S;
    string s = "#";
    for (int i = 0; i < S.length(); i++) {
        s += S[i];
        s += '#';
    }
    
    vector<int> arr = manacher(s);
    
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2) ans = max(ans, 1 + ((arr[i] - 1) / 2) * 2);
        else ans = max(ans, arr[i]);
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