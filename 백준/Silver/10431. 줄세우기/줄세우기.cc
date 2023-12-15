#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[25];

void solve() {
    int a;
    cin >> a;
    for (int i = 0; i < 20; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j]) ans++;
        }
    }
    cout << a << " " << ans << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}