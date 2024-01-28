#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
ll color[1005][1005];
ll cnt[1005];

void solve() {
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) cin >> color[i][j], cnt[i] += color[i][j], cnt[j] += color[i][j];
    }

    ll tot = (N * (N - 1) * (N - 2)) / 6;
    ll diff = 0;
    for (int i = 1; i <= N; i++) diff += cnt[i] * (N - 1 - cnt[i]);

    cout << tot - diff / 2 << '\n';

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