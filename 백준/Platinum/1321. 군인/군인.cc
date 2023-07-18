#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
ll arr[500005], seg[1000005];

void update(int pos, ll val) {
    for (seg[pos += N] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos ^ 1] + seg[pos];
    return;
}

ll query(ll l, ll r) {
    r++;
    ll ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            cin >> b >> c;
            update(b, c);
        } else {
            int b;
            cin >> b;
            int l = 1, r = N;
            int ans = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(1, mid) >= b) {
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            cout << ans << '\n';
        }
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