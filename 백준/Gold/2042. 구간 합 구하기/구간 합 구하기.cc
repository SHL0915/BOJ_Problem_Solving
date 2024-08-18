#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
ll arr[1000005];
ll fenwick[1000005];

void update(int pos, ll diff) {
    while (pos <= N) {
        fenwick[pos] += diff;
        pos += (pos & -pos);
    }
    return;
}

ll sum(int pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += fenwick[pos];
        pos -= (pos & -pos);
    }
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ll diff = c - arr[b];
            update(b, diff);
            arr[b] = c;
        } else cout << sum(c) - sum(b - 1) << '\n';
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