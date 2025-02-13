#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
ll arr[300005];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr, arr + N + 1);
    
    ll ans = 0;
    K++;
    
    int l = 0, r = N;
    while (K >= 2) {
        if (K >= 2) {
            ans += arr[r] - arr[l];
            l++, r--;
            K -= 2;
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