#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, H, W;
int arr[105];

void solve() {
    cin >> N >> H >> W;
    ll tot = 0;
    ll a = W, b = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i % 2) {
            b = arr[i];
            tot += min(a, W - b) * H;
            tot += min(b, W - a) * H;
        } else a = arr[i];
    }
    
    cout << tot;
    
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