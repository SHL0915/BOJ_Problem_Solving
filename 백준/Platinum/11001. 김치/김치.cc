#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, D;
ll T[100005], V[100005];
ll ans[100005];

void dnc(int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = (l + r) / 2;
    pii M = {-1, -1};
    for (int i = max(optl, m - D); i <= min(m, optr); i++) {
        M = max(M, {V[i] + (m - i) * T[m], i});
    }

    ans[m] = M.first;
    dnc(l, m - 1, optl, M.second);
    dnc(m + 1, r, M.second, optr);
    return;
}

void solve() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 1; i <= N; i++) cin >> V[i];

    dnc(1, N, 1, N);

    ll aans = -1;
    aans = *max_element(ans + 1, ans + N + 1);

    cout << aans;
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