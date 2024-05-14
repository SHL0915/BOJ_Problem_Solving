#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
    cin >> S;
    int a = 0, b = 0, ans = 0;
    for (int i = 0; i < S.length(); i++) {
        int now;
        if (S[i] == 'P') now = 0;
        else now = 1;
        
        if (now) {
            if (a) a--;
            b++;
        } else {
            if (b) b--;
            a++;
        }
        ans = max({ans, a, b});
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