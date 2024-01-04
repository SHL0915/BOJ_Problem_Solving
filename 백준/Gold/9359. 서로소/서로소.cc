#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, A, B;
int sieve[100005];
vector<ll> prime;

ll f(ll a, vector<pii> &p) {
    ll ret = 0;
    for (int i = 0; i < p.size(); i++) {
        ll now = p[i].first, cnt = p[i].second;
        if (cnt % 2) ret += a / now;
        else ret -= a / now;
    }
    return ret;
}

void solve() {
    cin >> A >> B >> N;
    vector<ll> p;
    
    for (int i = 0; i < prime.size(); i++) {
        ll now = prime[i];
        if (now * now > N) break;
        if (N % now) continue;
        else {
            p.push_back(now);
            while (1) {
                if (N % now) break;
                else N /= now;
            }
        }
    }
    
    if (N != 1) p.push_back(N);
    
    vector<pii> pp;
    for (int i = 1; i < (1 << p.size()); i++) {
        ll now = 1, flag = 0, cnt = 0;
        for (int j = 0; j < p.size(); j++) {
            if (i & (1 << j)) now *= p[j], cnt++;
            if (now > B) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        pp.push_back({now, cnt});
    }
    
    ll ans = f(B, pp) - f(A - 1, pp);
    ans = (B - A + 1) - ans;
    
    cout << ans << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (ll i = 2; i * i <= 1000000005LL; i++) {
        if (sieve[i] == 0) {
            prime.push_back(i);
            for (ll j = i * i; j * j <= 1000000005LL; j += i) sieve[j] = 1;
        }
    }
    int t = 1, tc = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << tc << ": ";
        solve();
        tc++;
    }
    return 0;
}