#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N;
ll arr[100005], fact[100005];

void solve() {
    cin >> N;
    ll tot = 0, ans = 0;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        fact[i] = (fact[i - 1] * i) % mod;
        ans += tot * arr[i];
        tot += arr[i];
    }

    cout << ans << "\n" << (fact[N] * fact[N - 1]) % mod;

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