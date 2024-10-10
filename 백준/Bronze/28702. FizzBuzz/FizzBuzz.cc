#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B, C;

bool isNum(string s) {
    if (s[0] == 'F' || s[0] == 'B') return false;
    else return true;
}

void solve() {
    cin >> A >> B >> C;
    
    int ans = 0;
    if (isNum(A)) {
        for (int i = 0; i < A.length(); i++) ans *= 10, ans += A[i] - '0';
        ans += 3;
    } else if (isNum(B)) {
        for (int i = 0; i < B.length(); i++) ans *= 10, ans += B[i] - '0';
        ans += 2;
    } else if (isNum(C)) {
        for (int i = 0; i < C.length(); i++) ans *= 10, ans += C[i] - '0';
        ans += 1;
    }
    
    if (ans % 3 == 0 && ans % 5 == 0) cout << "FizzBuzz";
    else if (ans % 3 == 0) cout << "Fizz";
    else if (ans % 5 == 0) cout << "Buzz";
    else cout << ans;
    
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