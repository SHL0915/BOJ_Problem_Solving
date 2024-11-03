#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, S;
ll arr[100005], psum[100005];

void solve() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> arr[i], psum[i] = psum[i - 1] + arr[i];
    
    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        if (psum[i] >= S) {
            int idx = upper_bound(psum, psum + i + 1, psum[i] - S) - psum;
            ans = min(ans, i - idx + 1);
        }
    }
    
    if (ans == 1e9) cout << 0;
    else cout << ans;
    
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