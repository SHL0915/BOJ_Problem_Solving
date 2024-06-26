#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        arr[i] = arr[i - 1] + a;
    }

    for (int i = N + 1; i <= 2 * N; i++) arr[i] = arr[i - N] + arr[N];

    ll tot = arr[N], ans = 0;

    int idx = 0;
    for (int i = 0; i < N; i++) {
        while (idx < 2 * N) {
            if (2 * (arr[idx] - arr[i]) > tot) break;
            ans = max(ans, min(arr[idx] - arr[i], tot - (arr[idx] - arr[i])));
            idx++;
        }
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