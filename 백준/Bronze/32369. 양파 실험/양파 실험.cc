#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, A, B;

void solve() {
    cin >> N >> A >> B;

    int a = 1, b = 1;

    for (int i = 0; i < N; i++) {
        a += A, b += B;
        if (b > a) swap(a, b);
        else if (a == b) b--;
    }

    cout << a << " " << b;

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