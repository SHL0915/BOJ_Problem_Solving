#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 9;

int N, M, T;
ll graph[105][105];
ll m[105][105];

void mul(ll A[105][105], ll B[105][105]) {
    ll temp[105][105];
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            temp[i][j] = 0;
            for (int a = 0; a < 105; a++) {
                temp[i][j] += A[i][a] * B[a][j];
                temp[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) A[i][j] = temp[i][j];
    }
    return;
}

void solve() {
    cin >> N >> M >> T;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            graph[b * 2][c * 2]++;
            graph[c * 2][b * 2]++;
            m[b * 2][c * 2]++;
            m[c * 2][b * 2]++;
        } else {
            cin >> b >> c >> d;
            graph[b * 2][b * 2 - 1] = 1;
            graph[b * 2 - 1][c * 2]++;
            graph[b * 2 - 1][d * 2]++;

            graph[c * 2][c * 2 - 1] = 1;
            graph[c * 2 - 1][b * 2]++;
            graph[c * 2 - 1][d * 2]++;

            graph[d * 2][d * 2 - 1] = 1;
            graph[d * 2 - 1][c * 2]++;
            graph[d * 2 - 1][b * 2]++;

            m[b * 2][b * 2 - 1] = 1;
            m[b * 2 - 1][c * 2]++;
            m[b * 2 - 1][d * 2]++;

            m[c * 2][c * 2 - 1] = 1;
            m[c * 2 - 1][b * 2]++;
            m[c * 2 - 1][d * 2]++;

            m[d * 2][d * 2 - 1] = 1;
            m[d * 2 - 1][c * 2]++;
            m[d * 2 - 1][b * 2]++;
        }
    }

    T--;
    while (T) {
        if (T % 2) mul(graph, m);
        mul(m, m);
        T >>= 1;
    }


    for (int i = 1; i <= N; i++) cout << graph[2][i * 2] << '\n';

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
