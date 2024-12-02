#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int arr[200005];

void solve() {
    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int l = 0, r = N - 1;
    for (int i = 0; i < N; i++) {
        if (arr[i] >= K) {
            ans++;
            r = min(r, i - 1);
        }
    }

    while (l < r) {
        if (arr[l] + arr[r] >= K) {
            ans++;
            l++;
            r--;
        } else l++;
    }

    if (ans) cout << ans;
    else cout << -1;

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