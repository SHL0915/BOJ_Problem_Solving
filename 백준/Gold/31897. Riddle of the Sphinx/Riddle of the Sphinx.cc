#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[5];

int f(int a, int b, int c) {
    int ret;
    cout << a << " " << b << " " << c << endl;
    cin >> ret;
    return ret;
}

void solve() {
    int abc = f(1, 1, 1);
    int a = f(1, 0, 0);
    int b = f(0, 1, 0);
    int c = f(0, 0, 1);
    int v = f(1, 2, 4);
    
    if ((a + b + c == abc) || (a + 2 * b + 4 * c == v)) cout << a << " " << b << " " << c << endl;
    else {
        int na = abc - (b + c);
        int nb = abc - (a + c);
        int nc = abc - (a + b);
        if (na + 2 * b + 4 * c == v) cout << na << " " << b << " " << c << endl;
        else if (a + 2 * nb + 4 * c == v) cout << a << " " << nb << " " << c << endl;
        else cout << a << " " << b << " " << nc << endl;
    }
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}