#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
ll arr[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N, greater<>());
    
    ll ans = 0;
    ll sum = 0;
    
    ll idx = N;
    
    for (int i = 0; i < N; i++) {
        if (sum * i + arr[i] > (sum + arr[i]) * (i + 1)) {
            idx = i;
            break;
        } else sum += arr[i];
    }
    
    for (int i = 0; i < idx; i++) ans += arr[i] * idx;
    for (int i = idx; i < N; i++) ans += arr[i];
    
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