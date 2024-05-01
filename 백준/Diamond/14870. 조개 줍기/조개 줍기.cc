#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1505][1505];
ll dp[1505][1505];
vector<ll> _seg[1505];

ll DP(int x, int y) {
    if (x < 1 || y < 1) return -1e15;
    if (x == 1 && y == 1) return arr[y][x];
    ll &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;
    ret = max(DP(x - 1, y), DP(x, y - 1)) + arr[y][x];
    return ret;
}

void update(int pos, ll val, vector<ll> &seg) {
    for (seg[pos += (N + 2)] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

ll query(int l, int r, vector<ll> &seg) {
    r++;
    ll ret = 0;
    for (l += (N + 2), r += (N + 2); l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

ll f(int x, int y) {
    return DP(x, y) + query(1, x, _seg[y]);
}

void solve() {
    cin >> N;
    _seg[0].resize(2 * N + 5, 0);
    for (int i = 1; i <= N; i++) {
        _seg[i].resize(2 * N + 5, 0);
        for (int j = 1; j <= N; j++) cin >> arr[i][j];
    }

    memset(dp, -1, sizeof(dp));

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) ans += f(j, i);
    }

    cout << ans << '\n';

    for (int i = 0; i < N; i++) {
        char a;
        int x, y;
        cin >> a >> y >> x;

        int l = x, r = x;
        if (a == 'U') {
            arr[y][x]++;
            r++;
            for (; r <= N; r++) {
                if (f(r - 1, y) >= f(r, y - 1)) continue;
                else break;
            }
            r--;

            ans += (r - l + 1);
            update(l, 1, _seg[y]);
            update(r + 1, -1, _seg[y]);

            for (int j = y + 1; j <= N; j++) {
                r++;
                for (; r <= N; r++) {
                    if (f(r - 1, j) >= f(r, j - 1)) continue;
                    else break;
                }
                r--;

                for (; l <= r; l++) {
                    if (f(l - 1, j) >= f(l, j - 1)) continue;
                    else break;
                }

                if (l > r) continue;
                ans += (r - l + 1);
                update(l, 1, _seg[j]);
                update(r + 1, -1, _seg[j]);
            }
        } else {
            arr[y][x]--;
            r++;
            for (; r <= N; r++) {
                if (f(r - 1, y) > f(r, y - 1)) continue;
                else break;
            }
            r--;

            ans -= (r - l + 1);
            update(l, -1, _seg[y]);
            update(r + 1, 1, _seg[y]);

            for (int j = y + 1; j <= N; j++) {
                r++;
                for (; r <= N; r++) {
                    if (f(r - 1, j) > f(r, j - 1)) continue;
                    else break;
                }
                r--;

                for (; l <= r; l++) {
                    if (f(l - 1, j) > f(l, j - 1)) continue;
                    else break;
                }

                if (l > r) continue;
                ans -= (r - l + 1);
                update(l, -1, _seg[j]);
                update(r + 1, 1, _seg[j]);
            }
        }

        cout << ans << '\n';
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