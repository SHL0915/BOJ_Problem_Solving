#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll f[1000005];
ll psum[1000005];

void solve() {
    cin >> N;
    cout << psum[N] << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;

    for (int i = 1; i <= 1000000; i++) {
        for (int j = 1;; j++) {
            if (i * j > 1000000) break;
            f[i * j] += i;
        }
        psum[i] = f[i] + psum[i - 1];
    }

    cin >> t;
    while (t--) solve();
    return 0;
}