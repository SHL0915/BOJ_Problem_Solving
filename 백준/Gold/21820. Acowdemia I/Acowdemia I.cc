#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, L;
int arr[100005];

void solve() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int l = 0, r = N;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        int idx = lower_bound(arr, arr + N, mid) - arr;
        int cnt = 0;

        for (int i = idx - 1; i >= 0; i--) {
            if (arr[i] == mid - 1) cnt++;
        }

        int res = N - idx + min(cnt, L);

        if (res >= mid) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
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