#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
    int flag = 0;
    while (1) {
        string s;
        cin >> s;
        if (s == "#") {
            break;
        }
        
        if (S.length() != s.length()) flag = 1;
        int cnt = 0;
        for (int i = 0; i < S.length(); i++) if (S[i] != s[i]) cnt++;
        
        if (cnt != 1) flag = 1;
        
        S = s;
    }
    
    if (flag) cout << "Incorrect\n";
    else cout << "Correct\n";
    
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
    while (1) {
        cin >> S;
        if (S == "#") break;
        solve();
    }
    return 0;
}