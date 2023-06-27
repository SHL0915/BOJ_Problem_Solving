#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, C;
ll A[10005], B[10005];

void solve() {
    cin >> N >> C;

    A[0] = 1;
    B[0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= C; j++) {
            if(j - (N - i) <= 0) A[j] = B[j];
            else A[j] = (B[j] - B[j - (N - i) - 1] + mod) % mod;
        }

        B[0] = A[0];
        for(int j = 1; j <= C; j++) B[j] = (A[j] + B[j - 1]) % mod;
    }

    cout << B[C];
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