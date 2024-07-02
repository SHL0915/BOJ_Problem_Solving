#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

map<string, int> m;

void solve() {
    int M = 0;
    for (int i = 0; i < 7; i++) {
        string s;
        int a;
        cin >> s >> a;
        m[s] = a;
        M = max(M, a);
    }
    
    string ans = "";
    for (auto i: m) {
        if (i.second == M) ans = i.first;
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