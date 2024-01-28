#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, M;
ll fact[200005], invf[200005], in_degree[200005], sz[200005];
vector<int> tree[200005];
ll dp[200005];

ll inv(ll a) {
    ll bit = 1, ret = 1;
    while (bit <= mod - 2) {
        if (bit & (mod - 2)) ret = (ret * a) % mod;
        bit <<= 1;
        a = (a * a) % mod;
    }
    ret %= mod;
    return ret;
}

ll DP(int node) {
    ll &ret = dp[node];
    if (ret != -1) return ret;
    sz[node] = 1;
    ret = 1;

    for (int nxt: tree[node]) {
        ret *= DP(nxt), ret %= mod;
        sz[node] += sz[nxt];
        ret *= invf[sz[nxt]], ret %= mod;
    }

    ret *= fact[sz[node] - 1];
    ret %= mod;

    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= N; i++) if (in_degree[i] == 0) tree[0].push_back(i);

    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = (fact[i - 1] * i) % mod;
    invf[N] = inv(fact[N]);
    for (int i = N - 1; i >= 0; i--) invf[i] = (invf[i + 1] * (i + 1)) % mod;

    memset(dp, -1, sizeof(dp));
    cout << DP(0);

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