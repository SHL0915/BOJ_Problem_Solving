#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;

void solve() {
    string A;
    int ans = 0;
    while (1) {
        cin >> A;
        if (A == "#") {
            if (ans == 0) cout << "Correct\n";
            else cout << "Incorrect\n";
            break;
        }

        if (A.length() != S.length()) {
            ans = 1;
            S = A;
            continue;
        } else {
            int cnt = 0;
            for (int i = 0; i < S.length(); i++) {
                if (S[i] != A[i]) cnt++;
            }

            if (cnt != 1) ans = 1;
            S = A;
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
    while (1) {
        cin >> S;
        if (S == "#") break;
        solve();
    }
    return 0;
}