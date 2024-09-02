#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int ans[400005];

void f(int k, int l, int r) {
    if (k == 0) return;
    if (k == 1) {
        ans[l] = ans[r] = 1;
        return;
    }
    ans[l] = k;
    ans[r - 2] = k - 1;
    ans[r - 1] = k;
    ans[r] = k - 1;
    f(k - 2, l + 1, r - 3);
    return;
}

void solve() {
    cin >> N;
    f(N, 1, 2 * N);
    
    for (int i = 1; i <= 2 * N; i++) cout << ans[i] << " ";
    
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