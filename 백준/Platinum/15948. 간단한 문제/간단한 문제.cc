#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;
ll arr[55];
ll ans[55];
ll p[55];

ll f(ll n, ll k) {
    if (k == 0) return 1;
    ll ret = f((n + 1) / 2, k - 1);
    if (n % 2 == 0) ans[k] = n + p[k] - 2;
    else ans[k] = n;
    ret /= ans[k];
    ret *= (1 + ans[k]);
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> arr[i];
    f(N, M);
    for (int i = 1; i <= M; i++) cout << ans[i] * arr[i] << " ";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    p[0] = 1;
    for (int i = 1; i < 55; i++) p[i] = p[i - 1] * 2;
    //cin >> t;
    while (t--) solve();
    return 0;
}