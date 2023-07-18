#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, D;
ll T[100005], V[100005], dp[100005], P[100005];

ll C(int i, int j) {
    return (j - i) * T[j] + V[i];
}

void DNC(int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;

    for (int i = max(l, m); i <= min(r, m + D); i++) {
        if (dp[m] < C(m, i)) {
            dp[m] = C(m, i);
            P[m] = i;
        }
    }

    DNC(s, m - 1, l, P[m]);
    DNC(m + 1, e, P[m], r);

    return;
}


void solve() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 1; i <= N; i++) cin >> V[i];

    DNC(1, N, 1, N);

    ll ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dp[i]);

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