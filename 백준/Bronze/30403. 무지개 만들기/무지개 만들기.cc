#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string s;
map<char, int> m;
string A = "roygbiv", B = "ROYGBIV";

void solve() {
    cin >> N;
    cin >> s;
    for (int i = 0; i < N; i++) m[s[i]]++;
    int a = 1, b = 1;
    for (int i = 0; i < A.length(); i++) {
        if (m[A[i]] == 0) a = 0;
        if (m[B[i]] == 0) b = 0;
    }
    if (a && b) cout << "YeS";
    else if (a) cout << "yes";
    else if (b) cout << "YES";
    else cout << "NO!";
    
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