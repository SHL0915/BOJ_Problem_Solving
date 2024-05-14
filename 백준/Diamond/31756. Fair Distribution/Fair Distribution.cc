#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[200005];
ll tot;

void f(map<int, int> &m, bitset<200005> &bs) {
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
    
    return;
}

void solve() {
    cin >> N;
    
    map<int, int> m;
    bitset<200005> bs;
    
    ll g = -1, cnt = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
        m[arr[i].first]++;
        tot += arr[i].first;
        if (!arr[i].first) cnt++;
        if (g == -1) g = arr[i].second;
        else g = gcd(g, arr[i].second);
    }
    
    if (!tot) {
        cout << "Y";
        return;
    }
    
    f(m, bs);
    
    int ans = 0;
    if (cnt) {
        for (int i = 0; i <= tot; i++) {
            if (!bs[i]) continue;
            if (abs(2 * i - tot) % g == 0) ans = 1;
        }
    } else {
        for (int i = 1; i < tot; i++) {
            if (!bs[i]) continue;
            if (abs(2 * i - tot) % g == 0) ans = 1;
        }
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