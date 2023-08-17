#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod1 = 6643838879;
const ll mod2 = 2147483647;
const ll base = 31700000;

ll N, K;
ll arr[20005];

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i]++;
    }

    int l = 1, r = N;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;

        ll val1 = 0, val2 = 0, a = 1, b = 1;
        for (int i = 0; i < mid; i++) {
            val1 = ((val1 * base) % mod1 + arr[i]) % mod1;
            val2 = ((val2 * base) % mod2 + arr[i]) % mod2;
            a = (a * base) % mod1;
            b = (b * base) % mod2;
        }
        a = mod1 - a;
        b = mod2 - b;

        map<pii, int> m;
        m[{val1, val2}]++;

        int flag = 0;
        for (int i = 1; i <= N - mid; i++) {
            val1 = (val1 * base + a * arr[i - 1] + arr[i + mid - 1]) % mod1;
            val2 = (val2 * base + b * arr[i - 1] + arr[i + mid - 1]) % mod2;
            m[{val1, val2}]++;

            if (m[{val1, val2}] >= K) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
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