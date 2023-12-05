#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[105];

void solve() {
    cin >> N;
    ll tot = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second, tot += (arr[i].first * arr[i].second);
    
    bitset<100005> dp[105];
    dp[0][0] = 1;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= arr[i].second; j++) {
            dp[i] |= (dp[i - 1] << arr[i].first * j);
        }
    }
    
    if (tot % 2 || !dp[N][tot / 2]) cout << 0 << '\n';
    else cout << 1 << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 3;
    //cin >> t;
    while (t--) solve();
    return 0;
}