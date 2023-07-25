#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll A[3], B[3], C[3];
ll a[4000005], ab[4000005];

void solve() {
    for (int i = 0; i < 3; i++) cin >> A[i];
    for (int i = 0; i < 3; i++) cin >> B[i];
    for (int i = 0; i < 3; i++) cin >> C[i];

    for (int i = 0; i < B[0]; i++) {
        ll s = A[0] * i + A[1];
        ll e = A[0] * i + A[2];
        for (int j = s; j <= e; j++) a[j] = 1;
    }

    for (int i = 0; i < A[0]; i++) {
        ll s = B[0] * i + B[1];
        ll e = B[0] * i + B[2];
        for (int j = s; j <= e; j++) ab[j] = 1;
    }

    for (int i = 0; i < A[0] * B[0]; i++) ab[i] &= a[i];

    vector<int> v;
    for (int i = 0; i < A[0] * B[0]; i++) if (ab[i] == 1) v.push_back(i);

    for (int i = 0; i < A[0] * B[0]; i++) {
        ll s = C[0] * i + C[1];
        ll e = C[0] * i + C[2];

        ll ms = s % (A[0] * B[0]);
        ll me = e % (A[0] * B[0]);

        if (s / (A[0] * B[0]) == e / (A[0] * B[0])) {
            int idx = lower_bound(v.begin(), v.end(), ms) - v.begin();
            if (idx != v.size() && v[idx] <= me) {
                cout << s - s % (A[0] * B[0]) + v[idx];
                return;
            }
        } else {
            int idx = lower_bound(v.begin(), v.end(), ms) - v.begin();
            if (idx != v.size()) {
                cout << s - s % (A[0] * B[0]) + v[idx];
                return;
            }

            if (v.size() && v[0] <= me) {
                cout << e - e % (A[0] * B[0]) + v[0];
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