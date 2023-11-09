#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
ll arr[10005];

void solve() {
    cin >> N >> Q;
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b] += c;
        } else {
            ll ans = 0;
            for (int i = b; i <= c; i++) ans += arr[i];
            cout << ans << '\n';
        }
    }
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