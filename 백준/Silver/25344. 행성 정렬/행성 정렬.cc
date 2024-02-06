#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N - 2; i++) cin >> arr[i];

    ll ans = arr[1];
    for (int i = 2; i <= N - 2; i++) ans = lcm(ans, arr[i]);

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