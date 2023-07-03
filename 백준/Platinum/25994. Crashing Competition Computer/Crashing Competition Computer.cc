#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const double INF = 1e18;

ll N, T, R;
double P;
double table[2005][2005];
double val[2005];

double DP(int now, int saved);

void solve() {
    cin >> N >> T >> R;
    cin >> P;

    val[0] = 1;
    for (int i = 1; i <= N; i++) val[i] = val[i - 1] * (1 - P);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) table[i][j] = INF;
    }

    cout << DP(0, 0);
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

double DP(int now, int saved) {
    if (now == N) return T;
    double &ret = table[now][saved];
    if (ret != INF) return ret;

    if (now != saved) ret = min(ret, T + DP(now, now));
    ret = min(ret, (P * R + 1) / val[now + 1 - saved] + DP(now + 1, saved));

    return ret;
}