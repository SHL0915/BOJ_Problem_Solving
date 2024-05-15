#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B;

void solve() {
    getline(cin, A);
    getline(cin, B);
    
    int ans = 0;
    for (int i = 0; i < A.length(); i++) {
        if (i + B.length() > A.length()) break;
        int flag = 0;
        for (int j = 0; j < B.length(); j++) {
            if (A[i + j] != B[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            ans++;
            i += B.length() - 1;
        }
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