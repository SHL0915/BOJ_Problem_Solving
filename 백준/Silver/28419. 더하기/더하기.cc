#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    ll a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2) a += arr[i];
        else b += arr[i];
    }

    if (N == 3) {
        if (a >= b) cout << abs(a - b);
        else cout << -1;
    } else cout << abs(a - b);

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