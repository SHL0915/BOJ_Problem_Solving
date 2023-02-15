#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1000000007LL;

int N;
ll A[500001];
ll B[500001];
ll C[500001];
ll arr[500001];
ll psum[500001];
map <pii, ll> m;

tuple<ll, ll, ll> EEu(ll a, ll b) {
    if (b == 0) return { a, 1, 0 };
    ll g, x, y;
    tie(g, x, y) = EEu(b, a % b);
    return { g,y,x - a / b * y };
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
        ll g, x, y;
        tie(g, x, y) = EEu(A[i], B[i]);
        m[{A[i] / g, B[i] / g}] ++;   
    }
    int idx = 0;
    for (auto i = m.begin(); i != m.end(); i++) arr[idx++] = (*i).second;
    ll ans = 0;
    psum[0] = arr[0];
    for (int i = 1; i < N; i++) psum[i] = psum[i - 1] + arr[i];
    for (int i = 0; i < N; i++) {
        ans += arr[i] * (psum[N - 1] - psum[i]);
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

ll rev(ll a, ll b) {
    ll ret = a;
    ll bit = 1;
    ret = (ret + mod) % mod;
    b = (b + mod) % mod;
    while (bit <= (mod - 2)) {
        if (bit & (mod - 2)) ret = (ret * b) % mod;
        bit <<= 1;
        b = (b * b) % mod;
    }
    ret %= mod;
    return ret;
}