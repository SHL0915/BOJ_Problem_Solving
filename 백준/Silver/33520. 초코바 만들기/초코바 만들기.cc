#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<ll> A, B;

void solve() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        A.push_back(a);
        B.push_back(b);
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    cout << A[0] * B[0];

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