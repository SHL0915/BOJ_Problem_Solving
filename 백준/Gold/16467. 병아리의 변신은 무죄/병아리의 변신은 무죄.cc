#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 100000007;

ll N, K;
ll arr[15][15], m[15][15];

void multiply(ll A[15][15], ll B[15][15]) {
    ll temp[15][15] = {0};
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 15; k++) {
                temp[i][j] += (A[i][k] * B[k][j]) % mod;
                temp[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) A[i][j] = temp[i][j];
    }
    return;
}

ll _pow(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k % 2) ret = (ret * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ret;
}


void solve() {
    cin >> K >> N;

    if (K == 0) {
        cout << _pow(2, N) << '\n';
        return;
    }

    memset(arr, 0, sizeof(arr));
    memset(m, 0, sizeof(m));
    K++;

    for (int i = 0; i < K - 1; i++) arr[0][i] = 0;
    arr[0][K - 1] = 1;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            m[i][j] = 0;
        }
        m[i][(i - 1 + K) % K] = 1;
    }
    m[K - 1][K - 1] = 1;

    while (N) {
        if (N % 2) multiply(arr, m);
        multiply(m, m);
        N >>= 1;
    }

    assert(arr[0][K - 1] >= 0 && arr[0][K - 1] < mod);

    cout << arr[0][K - 1] << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}