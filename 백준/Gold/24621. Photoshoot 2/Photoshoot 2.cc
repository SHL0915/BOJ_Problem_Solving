#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[100005], B[100005], rev[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        rev[A[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        B[i] = rev[B[i]];
    }

    int ans = 0, m = 0x3f3f3f3f;
    for (int i = N; i >= 1; i--) {
        if (B[i] > m) ans++;
        m = min(B[i], m);
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