#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;

void solve() {
    cin >> N;

    if (N % 9) {
        cout << -1 << ' ';
        return;
    }

    for (int i = 1; i <= 81; i++) {
        ll X = N + i;
        if (X % 10) continue;
        ll sum = 0;
        while (X) {
            sum += (X % 10);
            X /= 10;
        }
        if (sum == i) {
            cout << N + i << " ";
            return;
        }
    }

    cout << -1 << " ";

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}