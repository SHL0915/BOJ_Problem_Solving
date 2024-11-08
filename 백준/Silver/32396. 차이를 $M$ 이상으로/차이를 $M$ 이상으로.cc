#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;
ll arr[1000005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (abs(arr[i] - arr[i - 1]) >= M) continue;
        else {
            ans++;
            i++;
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