#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, M;
ll arr[(1 << 20)], dp[(1 << 20)], dp2[(1 << 20)];

ll _pow(ll a, ll b) {
    ll ret = 1, now = a;
    while (b) {
        if (b & 1) ret = (ret * now) % mod;
        now = (now * now) % mod;
        b /= 2;
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int now = 0, k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            now += (1 << (a - 1));
        }
        arr[now]++;
    }

    for (int i = 0; i < (1 << M); i++) dp[i] = arr[i];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (1 << M); j++) if (j & (1 << i)) dp[j] = (dp[j] + dp[j ^ (1 << i)]) % mod;
    }

    for (int i = 0; i < (1 << M); i++) {
        ll now = dp[((1 << M) - 1) ^ i];
        dp2[i] = _pow(2, now);
    }

    ll ans = 0;
    for (int i = 0; i < (1 << M); i++) {
        int cnt = __builtin_popcount(i);
        if (cnt % 2) ans = (ans + mod - dp2[i]) % mod;
        else ans = (ans + dp2[i]) % mod;
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