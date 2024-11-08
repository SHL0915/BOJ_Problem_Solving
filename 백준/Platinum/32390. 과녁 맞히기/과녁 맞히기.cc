#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, M;
ll arr[5000005];
ll fact[5000005], ifact[5000005], pow_2[5000005];

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
    cin >> N >> M;
    
    ll ans = fact[N];
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        ans *= ifact[a];
        ans %= mod;
        
        ans *= pow_2[a - 1];
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
    
    fact[0] = 1;
    for (int i = 1; i <= 5000000; i++) fact[i] = (fact[i - 1] * i) % mod;
    ifact[5000000] = inv(fact[5000000]);
    for (int i = 4999999; i >= 0; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    
    pow_2[0] = 1;
    for (int i = 1; i <= 5000000; i++) pow_2[i] = (pow_2[i - 1] * 2) % mod;
    
    //cin >> t;
    while (t--) solve();
    return 0;
}