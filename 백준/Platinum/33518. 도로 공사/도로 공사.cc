#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1e9 + 7;

int N, M;
ll arr[200005];
ll A[200005], B[200005];

void solve() {
    cin >> N >> M;

    for (int i = 2; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) A[i] = 1, B[i] = 1;

    for (int i = 0; i < M; i++) {
        ll u, v, L, R;
        cin >> u >> v >> L >> R;
        if (arr[u] < arr[v]) swap(u, v);
        ll val = (R - max(L, arr[u] - arr[v]) + 1) % mod;
        A[u] *= val, A[u] %= mod;
        if ((L <= (arr[u] - arr[v])) && ((arr[u] - arr[v]) <= R)) val = (val + mod - 1) % mod;
        B[u] *= val, B[u] %= mod;
    }

    ll ans = 1;
    for (int i = 2; i <= N; i++) {
        ans *= (A[i] - B[i] + mod) % mod;
        ans %= mod;
    }

    cout << ans;

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