#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;

void solve() {
    cin >> N >> M;
    ll a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        ll in;
        cin >> in;
        a = max(a, in);
    }

    for (int i = 0; i < M; i++) {
        ll in;
        cin >> in;
        b = max(b, in);
    }

    cout << a + b;
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