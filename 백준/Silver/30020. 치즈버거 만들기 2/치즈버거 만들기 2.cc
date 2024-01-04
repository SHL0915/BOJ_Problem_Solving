#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B;

void solve() {
    cin >> A >> B;
    int diff = A - B;
    
    if (diff <= 0 || A < 2 * diff || B < diff) {
        cout << "NO";
        return;
    }
    
    cout << "YES\n";
    cout << diff << '\n';
    for (int i = 0; i < diff - 1; i++) cout << "aba\n", A--, B--;
    cout << 'a';
    for (int i = 0; i < B; i++) cout << "ba";
    
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