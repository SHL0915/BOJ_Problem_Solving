#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B;
ll dp[25][11][11][2][2];

ll DP(int now, int p, int pp, int t, int tt) {
    if (now == A.length()) return 1;
    ll &ret = dp[now][p][pp][t][tt];
    if (ret != -1) return ret;
    ret = 0;

    int a = A[now] - '0', b = B[now] - '0';

    if (t == 0 && tt == 0) {
        if (a == b) {
            if (a != p && a != pp) {
                int next;
                if (p == 10 && a == 0) next = 10;
                else next = a;
                ret += DP(now + 1, next, p, 0, 0);
            }
        } else {
            if (a != p && a != pp) {
                int next;
                if (p == 10 && a == 0) next = 10;
                else next = a;
                ret += DP(now + 1, next, p, 0, 1);
            }

            if (b != p && b != pp) {
                int next;
                if (p == 10 && b == 0) next = 10;
                else next = b;
                ret += DP(now + 1, next, p, 1, 0);
            }

            for (int i = a + 1; i <= b - 1; i++) {
                if (i == p || i == pp) continue;
                int next = i;
                ret += DP(now + 1, next, p, 1, 1);
            }
        }
    } else if (t == 0) {
        if (a != p && a != pp) {
            int next;
            if (p == 10 && a == 0) next = 10;
            else next = a;
            ret += DP(now + 1, next, p, 0, 1);
        }

        for (int i = a + 1; i < 10; i++) {
            if (i == p || i == pp) continue;
            int next = i;
            ret += DP(now + 1, next, p, 1, 1);
        }
    } else if (tt == 0) {
        if (b != p && b != pp) {
            int next;
            if (p == 10 && b == 0) next = 10;
            else next = b;
            ret += DP(now + 1, next, p, 1, 0);
        }

        for (int i = 0; i <= b - 1; i++) {
            if (i == p || i == pp) continue;
            int next = i;
            if (p == 10 && i == 0) next = 10;
            ret += DP(now + 1, next, p, 1, 1);
        }
    } else {
        for (int i = 0; i < 10; i++) {
            if (i == p || i == pp) continue;
            int next = i;
            if (p == 10 && i == 0) next = 10;
            ret += DP(now + 1, next, p, 1, 1);
        }
    }

    return ret;
}

void solve() {
    ll aa, bb;
    cin >> aa >> bb;

    while (aa) {
        A += (char) ('0' + aa % 10);
        aa /= 10;
    }
    while (A.size() < 20) A += '0';
    reverse(A.begin(), A.end());

    while (bb) {
        B += (char) ('0' + bb % 10);
        bb /= 10;
    }
    while (B.size() < 20) B += '0';
    reverse(B.begin(), B.end());

    memset(dp, -1, sizeof(dp));
    cout << DP(0, 10, 10, 0, 0);

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