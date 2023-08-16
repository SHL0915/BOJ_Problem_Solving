#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, Q;
ll arr[100005];
ll psum[100005];

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + arr[i];

    while (Q--) {
        ll X;
        cin >> X;

        int idx = lower_bound(arr + 1, arr + N + 1, X) - arr;

        ll A = (idx - 1) * X - psum[idx - 1];
        ll B = psum[N] - psum[idx - 1] - X * (N - idx + 1);
        
        cout << A + B << '\n';
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