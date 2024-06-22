#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[50005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N);
    
    int ans = 0, M = arr[0].second, m = arr[0].second;
    for (int i = 1; i < N; i++) {
        int d = arr[i].first - arr[i - 1].first;
        M += d, m -= d;
        ans = max(ans, M - arr[i].second);
        ans = max(ans, arr[i].second - m);
        M = max(M, arr[i].second);
        m = min(m, arr[i].second);
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