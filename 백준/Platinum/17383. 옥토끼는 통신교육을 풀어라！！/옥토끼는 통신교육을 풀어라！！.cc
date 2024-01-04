#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    int l = 1, r = arr[N - 1];
    int ans = -1;
    
    while (l <= r) {
        int m = (l + r) / 2;
        int tot = (arr[N - 1] - 1) / m + 1;
        for (int i = 0; i < N - 1; i++) {
            int val = (arr[i] - 1) / m + 1;
            tot += val - 1;
        }
        
        if (tot <= N) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
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