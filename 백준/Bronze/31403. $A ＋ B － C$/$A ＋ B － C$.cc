#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int A, B, C;

void solve() {
    cin >> A >> B >> C;
    cout << A + B - C << '\n';
    
    if (B < 10) A *= 10;
    else if (B < 100) A *= 100;
    else if (B < 1000) A *= 1000;
    else A *= 10000;
    
    cout << A + B - C << '\n';
    
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