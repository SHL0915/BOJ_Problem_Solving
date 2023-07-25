#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A[3], B[3], C[3];
set<ll> a, ab;

void solve() {
    for (int i = 0; i < 3; i++) cin >> A[i];
    for (int i = 0; i < 3; i++) cin >> B[i];
    for (int i = 0; i < 3; i++) cin >> C[i];

    for (int i = 0; i < B[0]; i++) {
        ll s = A[0] * i + A[1];
        ll e = A[0] * i + A[2];
        for (int j = s; j <= e; j++) a.insert(j);
    }

    for (int i = 0; i < A[0]; i++) {
        ll s = B[0] * i + B[1];
        ll e = B[0] * i + B[2];
        for (int j = s; j <= e; j++) {
            if (a.count(j)) ab.insert(j);
        }
    }

    for (int i = 0; i < A[0] * B[0]; i++) {
        ll s = C[0] * i + C[1];
        ll e = C[0] * i + C[2];

        ll ms = s % (A[0] * B[0]);
        ll me = e % (A[0] * B[0]);

        if (s / (A[0] * B[0]) == e / (A[0] * B[0])) {
            auto itr = ab.lower_bound(ms);
            if (itr != ab.end() && *itr <= me) {
                cout << s - s % (A[0] * B[0]) + *itr;
                return;
            }
        } else {
            auto itr = ab.lower_bound(ms);
            if (itr != ab.end()) {
                cout << s - s % (A[0] * B[0]) + *itr;
                return;
            }

            if (ab.size() && *(ab.begin()) <= me) {
                cout << e - e % (A[0] * B[0]) + *(ab.begin());
                return;
            }
        }
    }

    cout << -1;
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