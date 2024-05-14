#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
map<int, int> m;
bitset<200005> bs;

void solve() {
    cin >> N;
    
    ll tot = 0;
    
    ll g = -1, cnt = 0;
    
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        tot += a;
        if (!a) cnt++;
        else m[a]++;
        if (g == -1) g = b;
        else g = gcd(g, b);
    }
    
    vector<ll> v;
    for (auto a: m) {
        ll k = 1, cnt = a.second;
        while (k <= cnt) {
            v.push_back(a.first * k);
            cnt -= k;
            k <<= 1;
        }
        v.push_back(a.first * cnt);
    }
    
    bs[0] = 1;
    for (ll a: v) bs |= (bs << a);
    
    int ans = 0;
    for (int i = 0; i <= tot; i++) {
        if ((i == 0 || i == tot) && !cnt) continue;
        if (!bs[i]) continue;
        if (abs(2 * i - tot) % g == 0) ans = 1;
    }
    
    if (ans) cout << "Y";
    else cout << "N";
    
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