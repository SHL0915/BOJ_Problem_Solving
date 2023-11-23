#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int arr[1000005];

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int now = arr[0] + K;
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (now < arr[i]) ans++, now = arr[i] + K;
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