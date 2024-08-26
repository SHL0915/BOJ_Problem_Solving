#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int ans[200005];

void solve() {
    cin >> N;
    int l = 1, r = N;
    int now = 1, t = 0;
    while (l <= r) {
        if (!t) ans[l++] = now++;
        else ans[r--] = now++;
        t ^= 1;
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << " ";

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