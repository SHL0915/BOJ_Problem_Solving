#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll K;
vector<ll> val;

void BackTracking(int now, int pos, ll k) {
    if (pos == 0) {
        val.push_back(k);
        return;
    } else {
        for (int i = 0; i < now; i++) BackTracking(i, pos - 1, k * 10 + i);
    }
    return;
}

void solve() {
    cin >> K;
    if (K == 0) cout << 0;
    else {
        if (K > val.size()) cout << -1;
        else cout << val[K - 1];
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

    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) BackTracking(j, i, j);
    }
    sort(val.begin(), val.end());

    //cin >> t;
    while (t--) solve();
    return 0;
}