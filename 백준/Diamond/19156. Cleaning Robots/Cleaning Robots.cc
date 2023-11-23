#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
vector<int> tree[100005];
ll dp[100005][3];

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

ll h1(int node, int par, int t) {
    int cnt = 0, idx = -1;
    ll ret = 0;
    ll pi = 1;
    for (int next: tree[node]) {
        if (next == par) continue;
        if (dp[next][t] == 0) cnt++, idx = next;
        else pi = (pi * dp[next][t]) % mod;
    }
    
    if (cnt > 1) return 0;
    else if (cnt == 1) return (dp[idx][2] * pi) % mod;
    else {
        for (int next: tree[node]) {
            if (next == par) continue;
            ret += (((dp[next][2] * inv(dp[next][t])) % mod) * pi) % mod;
            ret %= mod;
        }
        return ret;
    }
}

ll h2(int node, int par, int t) {
    int cnt = 0, idx1 = -1, idx2 = -1;
    ll ret = 0, pi = 1;
    
    for (int next: tree[node]) {
        if (next == par) continue;
        if (dp[next][t] == 0) {
            if (cnt == 0) idx1 = next;
            else if (cnt == 1) idx2 = next;
            cnt++;
        } else pi = (pi * dp[next][t]) % mod;
    }
    
    if (cnt > 2) return 0;
    else if (cnt == 2)
        return ((((dp[idx1][2] * dp[idx2][2]) % mod) * ((inv(dp[idx1][t]) * inv(dp[idx2][t])) % mod)) % mod * pi) % mod;
    else if (cnt == 1) {
        pi = (pi * dp[idx1][2]) % mod;
        for (int next: tree[node]) {
            if (next == par || next == idx1) continue;
            ret += (((dp[next][2] * inv(dp[next][t])) % mod) * pi) % mod;
            ret %= mod;
        }
        return ret;
    } else {
        ll temp = 0;
        for (int next: tree[node]) {
            if (next == par) continue;
            temp += (((dp[next][2] * inv(dp[next][t])) % mod) * pi) % mod;
            temp %= mod;
        }
        
        for (int next: tree[node]) {
            if (next == par) continue;
            ret += (((dp[next][2] * inv(dp[next][t])) % mod) * temp) % mod;
            ret %= mod;
            ll a = (((dp[next][2] * dp[next][2] % mod) * (inv(dp[next][t]) * inv(dp[next][t]) % mod) % mod) * pi) % mod;
            ret += (mod - a);
            ret %= mod;
        }
        
        ret *= inv(2);
        ret %= mod;
        
        return ret;
    }
}

ll h3(int node, int par, int t) {
    ll ret = 1;
    for (int next: tree[node]) {
        if (next == par) continue;
        ret = (ret * dp[next][t]) % mod;
    }
    return ret;
}

void DP(int node, int par) {
    
    for (int next: tree[node]) {
        if (next == par) continue;
        DP(next, node);
    }
    
    ll a0 = h1(node, par, 0);
    ll a1 = h1(node, par, 1);
    ll b0 = h2(node, par, 0);
    ll c1 = h3(node, par, 1);
    
    dp[node][0] = (a1 + b0 + c1) % mod;
    dp[node][1] = b0 % mod;
    dp[node][2] = (a0 + c1) % mod;
    
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DP(1, 1);
    
    cout << dp[1][0];
    
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