#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
int sieve[1000005];
vector<ll> prime;
ll p[11];

void solve() {
    ll org = N;
    
    string ans = "";
    for (int i = 10; i >= 0; i--) {
        if (N / p[i] > 0) {
            for (int j = i; j >= 1; j--) {
                string s = to_string(prime[j]);
                reverse(s.begin(), s.end());
                ans += s + "*";
            }
            string s = to_string(N / p[i]);
            reverse(s.begin(), s.end());
            ans += s;
            ans += " + ";
            N %= p[i];
        }
    }
    
    ans.pop_back();
    ans.pop_back();
    ans += "= ";
    reverse(ans.begin(), ans.end());
    
    cout << org << ans << endl;
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    prime.push_back(1);
    for (ll i = 2; i <= 1000000; i++) {
        if (!sieve[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= 1000000; j += i) sieve[j] = 1;
        }
    }
    
    p[0] = prime[0];
    for (int i = 1; i <= 10; i++) p[i] = p[i - 1] * prime[i];
    
    int t = 1;
    //cin >> t;
    while (1) {
        cin >> N;
        if (N == 0) break;
        solve();
    }
    return 0;
}