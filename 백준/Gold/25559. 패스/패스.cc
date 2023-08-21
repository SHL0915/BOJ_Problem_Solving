#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    if (N == 1) cout << 1;
    else if (N % 2) cout << -1;
    else {
        cout << N << " ";
        int a = N - 1, b = 2;
        for (int i = 1; i < N; i++) {
            if (i % 2) {
                cout << a << " ";
                a -= 2;
            } else {
                cout << b << " ";
                b += 2;
            }
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
    while (t--) solve();
    return 0;
}