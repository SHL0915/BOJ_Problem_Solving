#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, M, ans;
int sieve[1000001];
int isProduct[1000001];
int mark[10];
vector <ll> prime;

void BackTracking(int k, string s);

void solve() {
    cin >> K >> M;

    sieve[0] = 1; sieve[1] = 1;
    for (ll i = 2; i <= 1000000; i++) {
        if (sieve[i] == 0) {
            prime.push_back(i);
            for (ll j = i * i; j <= 1000000; j += i) sieve[j] = 1;
        }
    }

    for (int i = 0; i < prime.size(); i++) {
        for (int j = i; j < prime.size(); j++) {
            ll now = prime[i] * prime[j];
            if (now > 1000000) break;
            isProduct[now] = 1;
        }
    }

    BackTracking(0, "");

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

void BackTracking(int k, string s) {
    if (k == K) {
        ll now = 0;
        for (int i = 0; i < s.length(); i++) {
            now *= 10;
            now += (s[i] - '0');
        }

        int flag = 0;
        for (int i = 0; i < prime.size(); i++) {
            ll p = prime[i];
            if (now - p < 0) continue;
            if (now - p != p && sieve[now - p] == 0) flag = 1;
        }

        if (flag == 0) return;

        while (1) {
            if (now % M) break;
            else now /= M;
        }

        if (isProduct[now] == 1) ans++;        
        return;
    }
    else {
        for (int i = 0; i < 10; i++) {
            if (mark[i]) continue;
            if (k == 0 && i == 0) continue;
            mark[i] = 1;
            BackTracking(k + 1, s + (char)('0' + i));
            mark[i] = 0;
        }
    }
}