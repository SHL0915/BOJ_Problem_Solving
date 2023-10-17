#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void move(int now, int a, int b, int c) {
    if (now < 1) return;
    else {
        move(now - 1, a, c, b);
        cout << a << " " << c << '\n';
        move(now - 1, b, a, c);
        return;
    }
}

void solve() {
    cin >> N;
    cout << (1LL << N) - 1 << '\n';
    move(N, 1, 2, 3);
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