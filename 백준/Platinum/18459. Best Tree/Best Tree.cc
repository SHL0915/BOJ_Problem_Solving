#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];

void solve() {
    cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] >= 2) cnt++;
    }

    if (N == 2) cout << 1 << '\n';
    else cout << min(cnt, N / 2) << '\n';

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