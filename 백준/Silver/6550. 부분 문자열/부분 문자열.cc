#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S, T;

void solve() {
    while (cin >> S >> T) {
        int s = 0;
        int flag = 0;
        for (int i = 0; i < T.length(); i++) {
            if (S[s] == T[i]) s++;
            if (s == S.length()) {
                flag = 1;
                break;
            }
        }

        if (flag) cout << "Yes\n";
        else cout << "No\n";
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