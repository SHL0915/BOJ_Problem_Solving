#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;

void solve() {
    cin >> N;
    
    ll sqrtN = sqrt(N);
    ll ans = 0x3f3f3f3f3f3f3f3fLL;
    for (int i = max(1LL, sqrtN - 10); i <= min(N, sqrtN + 10); i++) {
        ans = min(ans, 2 * (i + ((N - 1) / i + 1)));
    }
    
    cout << ans << '\n';
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