#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

ll T, N, D;
ll arr[105][25][25];
ll cycle[25][25];
ll ans[25][25];

void mul(ll A[25][25], ll B[25][25]) {
    ll temp[25][25] = {0};
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 25; k++) temp[i][j] += A[i][k] * B[k][j], temp[i][j] %= mod;
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) A[i][j] = temp[i][j];
    }

    return;
}

void solve() {
    cin >> T >> N >> D;
    for (int i = 0; i < T; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            arr[i][a][b] += c;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cycle[i][j] = arr[0][i][j];
    }
    for (int i = 1; i < T; i++) mul(cycle, arr[i]);

    for (int i = 0; i < N; i++) ans[i][i] = 1;
    ll t = D / T;

    while (t) {
        if (t & 1) mul(ans, cycle);
        mul(cycle, cycle);
        t >>= 1;
    }

    for (int i = 0; i < D % T; i++) mul(ans, arr[i]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << ans[i][j] << " ";
        cout << '\n';
    }


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