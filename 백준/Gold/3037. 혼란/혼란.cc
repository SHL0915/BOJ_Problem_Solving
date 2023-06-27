#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, C;
ll table[1005][10005];
ll psum[10005];

void solve() {
    cin >> N >> C;

    table[0][0] = 1;
    psum[0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= C; j++) {
            if(j - (N - i) <= 0) table[i][j] = psum[j];
            else table[i][j] = (psum[j] - psum[j - (N - i) - 1] + mod) % mod;
        }

        psum[0] = table[i][0];
        for(int j = 1; j <= C; j++) psum[j] = (table[i][j] + psum[j - 1]) % mod;
    }

    cout << psum[C];
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