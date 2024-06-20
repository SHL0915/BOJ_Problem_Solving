#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

void solve() {
    cin >> N >> K;
    ll sum = 0;
    for (int i = 1; i <= K; i++) sum += i;

    if (sum > N) cout << -1;
    else {
        int R = N - sum;
        R %= K;
        if (R == 0) cout << K - 1;
        else cout << K;
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