#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[1005];

void solve() {
    cin >> N;

    ll ans = -1;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll now = arr[i] * arr[j];
            string s = to_string(now);

            int flag = 0;
            for (int k = 1; k < s.length(); k++) {
                if (s[k] != s[k - 1] + 1) flag = 1;
            }

            if (flag) continue;
            else ans = max(ans, now);
        }
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