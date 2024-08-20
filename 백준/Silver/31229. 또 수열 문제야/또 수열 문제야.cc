#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int sieve[1000005];
vector<int> prime;

void solve() {
    cin >> N;

    for(int i = 0; i < N; i++) cout << prime[i] << " ";

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (ll i = 2; i <= 1000000; i++) {
        if (!sieve[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= 1000000; j += i) sieve[j] = 1;
        }
    }
    //cin >> t;
    while (t--) solve();
    return 0;
}