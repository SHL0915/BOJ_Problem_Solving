#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    int cnt = 0;
    
    int use = -15;
    
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) cnt++;
        else {
            if (i - use >= 2) use = i;
            else cnt = 0;
        }
        ans = max(ans, cnt);
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