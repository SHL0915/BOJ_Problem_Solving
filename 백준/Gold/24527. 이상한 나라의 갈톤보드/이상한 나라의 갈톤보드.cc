#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, Q, R;
ll S[100005];
double psum[100005];

void solve() {
    cin >> H >> Q >> R;
    while (Q--) {
        ll a, b;
        cin >> a >> b;
        ll h = upper_bound(S, S + H + 1, a) - S - 1;
        ll len = H + 2 - h, pos = a - S[h] + 1;
        ll l = pos, r = pos + len - 1;
        double val = (double) (b) / (double) (len);
        psum[l] += val;
        psum[r + 1] -= val;
    }

    for (int i = 1; i <= (H + 1); i++) psum[i] += psum[i - 1];
    for (int i = 1; i <= (H + 1); i++) psum[i] += psum[i - 1];

    while (R--) {
        ll a, b;
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << '\n';
    }

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    S[1] = 1;
    for (int i = 2; i < 100005; i++) S[i] = S[i - 1] + i - 1;

    //cin >> t;
    while (t--) solve();
    return 0;
}