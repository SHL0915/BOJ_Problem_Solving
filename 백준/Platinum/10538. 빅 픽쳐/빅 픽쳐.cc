#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod1 = 998244353;
const ll mod2 = 6643838879;
const ll base1 = 752;
const ll base2 = 1253;

int H, W, N, M;
ll val;
string arr[2005];
ll v[2005][2005];
ll vv[2005];

void solve() {
    cin >> N >> M >> H >> W;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ll now = 0;
        for (int j = 0; j < M; j++) {
            now *= base1, now %= mod1;
            now += s[j], now %= mod1;
        }
        vv[i] = now;
    }

    val = 0;
    for (int i = 0; i < N; i++) {
        val *= base2, val %= mod2;
        val += vv[i], val %= mod2;
    }

    for (int i = 0; i < H; i++) {
        cin >> arr[i];
        ll now = 0, p = 1;
        for (int j = 0; j < M; j++) {
            now *= base1, now %= mod1;
            now += arr[i][j], now %= mod1;
            if (j) p *= base1, p %= mod1;
        }
        v[i][0] = now;
        for (int j = 0; j < W - M; j++) {
            now += (mod1 - (p * arr[i][j]) % mod1), now %= mod1;
            now *= base1, now %= mod1;
            now += arr[i][j + M], now %= mod1;
            v[i][j + 1] = now;
        }
    }

    ll ans = 0;

    for (int i = 0; i <= W - M; i++) {
        ll now = 0, p = 1;
        for (int j = 0; j < N; j++) {
            now *= base2, now %= mod2;
            now += v[j][i], now %= mod2;
            if (j) p *= base2, p %= mod2;
        }
        ans += (val == now);

        for (int j = 0; j < H - N; j++) {
            now += (mod2 - (p * v[j][i]) % mod2), now %= mod2;
            now *= base2, now %= mod2;
            now += v[j + N][i], now %= mod2;

            ans += (val == now);
        }
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
    int t = 1, tc = 1;
    //cin >> t;
    while (t--) {
        //cout << "#" << tc++ << " ";
        solve();
    }
    return 0;
}