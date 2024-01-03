#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll W, N;
ll arr[100005];
ll lv[100005], rv[100005];
ll psum[100005];

ll f(ll l, ll r) {
    return (r * (r + 1)) / 2 - (l * (l - 1)) / 2;
}

void solve() {
    cin >> W >> N;
    for (int i = 1; i <= W; i++) cin >> arr[i], lv[i] = arr[i], rv[i] = arr[i], psum[i] = arr[i] + psum[i - 1];
    for (int i = 1; i <= W; i++) {
        rv[i] += i;
        lv[i] += (N - i);
    }

    if (W == 1) {
        cout << arr[1];
        return;
    }

    ll l = 1, r = 1e18 + 1e9;
    ll ans = 0;

    while (l <= r) {
        ll m = (l + r) / 2;
        vector<int> lidx(W + 1), ridx(W + 1);
        int flag = 0;

        for (int i = 1; i <= W; i++) {
            if (arr[i] >= m) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            int idx = 0;
            for (int i = 2; i <= W - 1; i++) {
                ll diff = m - arr[i];
                idx = max(idx, i + 1);
                for (; idx <= W; idx++) {
                    if (rv[idx] >= rv[i] + diff) break;
                }
                ridx[i] = idx;
            }
            for (int i = W - 1; i >= 2; i--) {
                ll diff = m - arr[i];
                idx = min(idx, i - 1);
                for (; idx >= 1; idx--) {
                    if (lv[idx] >= lv[i] + diff) break;
                }
                lidx[i] = idx;
            }

            for (int i = 2; i <= W - 1; i++) {
                if (lidx[i] == 0 || ridx[i] == W + 1) continue;
                ll cost = f(m - (i - lidx[i] - 1), m) + f(m - (ridx[i] - i - 1), m) - m;
                ll tot = psum[ridx[i] - 1] - psum[lidx[i]];
                if (cost - tot <= N) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
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