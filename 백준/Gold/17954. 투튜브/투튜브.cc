#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[10005], B[10005];

void solve() {
    cin >> N;

    if (N == 1) {
        cout << 2 << '\n' << 1 << '\n' << 2;
        return;
    }

    A[N] = 2 * N;
    A[1] = 2 * N - 1;
    B[N] = 2 * N - 2;
    B[1] = 2 * N - 3;
    int now = 2 * N - 4;
    for (int i = 2; i <= N - 1; i++) {
        B[i] = now;
        now--;
    }

    for (int i = 2; i <= N - 1; i++) {
        A[i] = now;
        now--;
    }

    ll ans = 0, t = 0;

    for (int i = 1; i <= N; i++, t++) ans += (t * (t + 1)) / 2 * B[i];
    for (int i = 1; i <= N; i++, t++) ans += (t * (t + 1)) / 2 * A[i];

    cout << ans << '\n';
    for (int i = 1; i <= N; i++) cout << A[i] << " ";
    cout << '\n';
    for (int i = 1; i <= N; i++) cout << B[i] << " ";

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