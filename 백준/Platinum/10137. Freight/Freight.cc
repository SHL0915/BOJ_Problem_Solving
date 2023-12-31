#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, S;
ll arr[1000005];
ll dp[1000005];

void solve() {
    cin >> N >> S;
    arr[0] = -1;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] <= arr[i - 1]) arr[i] = arr[i - 1] + 1;
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    ll idx = -1;
    deque<ll> dq;
    dq.push_back(0);
    for (int i = 1; i <= N; i++) {
        while (dq.size()) {
            ll f = dq.front();
            if (dp[f] + i - f - 1 < arr[i]) {
                dq.pop_front();
                idx = max(idx, f);
            } else break;
        }

        if (idx != -1) dp[i] = min(dp[i], arr[i] + 2 * S + i - idx - 1);
        if (dq.size()) dp[i] = min(dp[i], dp[dq.front()] + 2 * (S + i - dq.front() - 1));

        while (dq.size()) {
            ll b = dq.back();
            if (dp[b] - 2 * b >= dp[i] - 2 * i) dq.pop_back();
            else break;
        }

        dq.push_back(i);
    }

    cout << dp[N];

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