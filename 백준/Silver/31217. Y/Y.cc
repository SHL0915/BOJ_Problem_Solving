#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

int N, M;
ll degree[100005];

void solve() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++, degree[v]++;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (degree[i] < 3) continue;
        else {
            ans += (degree[i] * (degree[i] - 1) * (degree[i] - 2)) / 6;
            ans %= mod;
        }
    }

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