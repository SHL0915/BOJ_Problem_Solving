#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, M, ans;
int sieve[1000005];
int mark[10];

void BruteForce(int k, int now) {
    if (k == K) {
        if (now % 2) {
            if (now == 1) return;
            if (sieve[now - 2]) return;
            
            ll a = now;
            while (1) {
                if (a % M) break;
                else a /= M;
            }
            
            int flag = 0;
            for (ll i = 1; i * i <= a; i++) {
                if (sieve[i]) continue;
                if (a % i) continue;
                if (sieve[a / i]) continue;
                flag = 1;
            }
            
            if (flag) ans++;
        } else {
            int f = 0;
            for (ll i = 2; i <= now / 2; i++) {
                if (!sieve[i] && !sieve[now - i] && i != now - i) {
                    f = 1;
                    break;
                }
            }
            if (!f) return;
            
            ll a = now;
            while (1) {
                if (a % M) break;
                else a /= M;
            }
            
            int flag = 0;
            for (ll i = 1; i * i <= a; i++) {
                if (sieve[i]) continue;
                if (a % i) continue;
                if (sieve[a / i]) continue;
                flag = 1;
            }
            
            if (flag) ans++;
        }
        
    } else {
        for (int i = 0; i < 10; i++) {
            if (!k && !i) continue;
            if (mark[i]) continue;
            mark[i] = 1;
            BruteForce(k + 1, now * 10 + i);
            mark[i] = 0;
        }
    }
}

void solve() {
    cin >> K >> M;
    
    BruteForce(0, 0);
    cout << ans;
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve[0] = 1;
    sieve[1] = 1;
    for (ll i = 2; i <= 1000000; i++) {
        if (sieve[i] == 0) {
            for (ll j = i * i; j <= 1000000; j += i) sieve[j] = 1;
        }
    }
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}