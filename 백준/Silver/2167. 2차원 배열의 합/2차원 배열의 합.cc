#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
ll arr[305][305];
ll psum[305][305];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> arr[i][j];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + arr[i][j];
    }
    
    cin >> K;
    while (K--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = psum[c][d] - psum[a - 1][d] - psum[c][b - 1] + psum[a - 1][b - 1];
        cout << ans << '\n';
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
