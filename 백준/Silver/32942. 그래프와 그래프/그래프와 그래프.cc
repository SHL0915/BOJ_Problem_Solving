#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A, B, C;

void solve() {
    cin >> A >> B >> C;
    
    for (int i = 1; i <= 10; i++) {
        vector<int> ans;
        for (int j = 1; j <= 10; j++) {
            if (A * i + B * j == C) ans.push_back(j);
        }
        if (ans.empty()) cout << 0 << '\n';
        else {
            for (int a: ans) cout << a << " ";
            cout << '\n';
        }
    }
    
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