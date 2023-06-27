#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

ll N;
ll arr[2][2];
ll res[2];

void mat_pow();

void mul();

void solve() {
    cin >> N;
    if (N % 2) {
        cout << 0;
        return;
    }
    N /= 2;
    N ++;

    arr[0][0] = 4;
    arr[0][1] = -1;
    arr[1][0] = 1;

    res[0] = 1;
    res[1] = 3;

    while (N) {
        if (N & 1) mul();
        mat_pow();
        N /= 2;
    }

    cout << res[0];
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

void mat_pow() {
    ll temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) temp[i][j] = 0;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                temp[i][j] += (arr[i][k] * arr[k][j]) % mod;
                temp[i][j] += mod;
                temp[i][j] %= mod;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) arr[i][j] = temp[i][j];
    }

    return;
}

void mul() {
    ll temp[2];
    for (int i = 0; i < 2; i++) temp[i] = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i] += (arr[i][j] * res[j]) % mod;
            temp[i] += mod;
            temp[i] %= mod;
        }
    }

    for (int i = 0; i < 2; i++) res[i] = temp[i];

    return;
}