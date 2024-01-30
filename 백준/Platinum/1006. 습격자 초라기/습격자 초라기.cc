#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, W;
int A[20005], B[20005];
int dp[20005][5][4];

int DP(int now, int t, int s) {
    int &ret = dp[now][t][s];
    if (ret != -1) return ret;
    ret = INF;

    int a, b;
    if (t == 0) a = now, b = now;
    else if (t == 1) a = now + 1, b = now;
    else if (t == 2) a = now, b = now + 1;
    else if (t == 3) a = now + 2, b = now;
    else if (t == 4) a = now, b = now + 2;

    if (a == N && b == N && s == 0) return ret = 0;
    if (a == N + 1 && b == N && s == 1) return ret = 0;
    if (a == N && b == N + 1 && s == 2) return ret = 0;
    if (a == N + 1 && b == N + 1 && s == 3) return ret = 0;

    if (a >= N + 2) return ret;
    if (b >= N + 2) return ret;

    int na, nb, nxt, nt;

    // case 1
    if (t != 3) {
        na = a + 1, nb = b;
        nxt = min(na, nb);
        if (na == nb) nt = 0;
        if (na == nb + 1) nt = 1;
        if (na == nb - 1) nt = 2;
        if (na == nb + 2) nt = 3;
        if (na == nb - 2) nt = 4;

        ret = min(ret, 1 + DP(nxt, nt, s));
    }

    // case 2
    if (t != 1 && t != 3) {
        if (A[a] + A[a + 1] <= W) {
            na = a + 2, nb = b;
            nxt = min(na, nb);
            if (na == nb) nt = 0;
            if (na == nb + 1) nt = 1;
            if (na == nb - 1) nt = 2;
            if (na == nb + 2) nt = 3;
            if (na == nb - 2) nt = 4;

            ret = min(ret, 1 + DP(nxt, nt, s));
        }
    }

    // case 3
    if (t == 0) {
        if (A[a] + B[b] <= W) {
            na = a + 1, nb = b + 1;
            nxt = min(na, nb);
            if (na == nb) nt = 0;
            if (na == nb + 1) nt = 1;
            if (na == nb - 1) nt = 2;
            if (na == nb + 2) nt = 3;
            if (na == nb - 2) nt = 4;

            ret = min(ret, 1 + DP(nxt, nt, s));
        }
    }

    // case 4
    if (t != 4) {
        na = a, nb = b + 1;
        nxt = min(na, nb);
        if (na == nb) nt = 0;
        if (na == nb + 1) nt = 1;
        if (na == nb - 1) nt = 2;
        if (na == nb + 2) nt = 3;
        if (na == nb - 2) nt = 4;

        ret = min(ret, 1 + DP(nxt, nt, s));
    }

    // case 5
    if (t != 2 && t != 4) {
        if (B[b] + B[b + 1] <= W) {
            na = a, nb = b + 2;
            nxt = min(na, nb);
            if (na == nb) nt = 0;
            if (na == nb + 1) nt = 1;
            if (na == nb - 1) nt = 2;
            if (na == nb + 2) nt = 3;
            if (na == nb - 2) nt = 4;

            ret = min(ret, 1 + DP(nxt, nt, s));
        }
    }

    //cout << a << " " << b << " " << ret << endl;

    return ret;
}


void solve() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> A[i], A[i + N] = A[i];
    for (int i = 0; i < N; i++) cin >> B[i], B[i + N] = B[i];

    memset(dp, -1, sizeof(dp));
    cout << min({DP(0, 0, 0), DP(0, 1, 1), DP(0, 2, 2), DP(1, 0, 3)}) << '\n';

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