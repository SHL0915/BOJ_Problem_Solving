#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 9;

int N;
ll arr[5005], v[5005][5005], dp[5005], fact[5005], ifact[5005];
vector<int> vv;

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

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i], vv.push_back(arr[i]);
    sort(arr + 1, arr + N + 1);
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    for (int i = 1; i <= N; i++) arr[i] = lower_bound(vv.begin(), vv.end(), arr[i]) - vv.begin();
    
    fact[0] = 1;
    ifact[0] = inv(fact[0]);
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i, fact[i] %= mod, ifact[i] = inv(fact[i]);
    
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 1; j <= N + 1; j++) v[i][j] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        int cnt[5005] = {0};
        ll val = 1;
        for (int j = i; j <= N; j++) {
            val *= (fact[cnt[arr[j]]] * ifact[j - i]) % mod, val %= mod;
            cnt[arr[j]]++;
            val *= (ifact[cnt[arr[j]]] * fact[j - i + 1]) % mod, val %= mod;
            v[i][j] = val;
        }
    }
    
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = v[1][i];
        for (int j = 1; j <= i; j++) {
            dp[i] -= (dp[j - 1] * v[j + 1][i]) % mod;
            dp[i] += mod;
            dp[i] %= mod;
        }
    }
    
    cout << dp[N];
    
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