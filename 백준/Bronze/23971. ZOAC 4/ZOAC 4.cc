#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, W, N, M;

void solve() {
    cin >> H >> W >> N >> M;
    int a = H / (N + 1);
    if (H % (N + 1)) a++;
    int b = W / (M + 1);
    if (W % (M + 1)) b++;
    
    cout << a * b;
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