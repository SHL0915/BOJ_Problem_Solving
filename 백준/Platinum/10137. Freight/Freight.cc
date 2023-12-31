#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, S;
ll arr[1000005];
ll dp[1000005];

void solve() {
    cin >> N >> S;
    arr[0] = -0x3f3f3f3f3f3f3f3fLL;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] <= arr[i - 1]) arr[i] = arr[i - 1] + 1;
    }
    dp[0] = 0;

    ll idx = 0;
    deque<ll> dq, dq2;
    for (int i = 1; i <= N; i++) {
        while (dq2.size()) {
            ll f = dq2.front();
            if (dp[f] + i - f - 1 < arr[i]) {
                dq2.pop_front();
                idx = max(idx, f);
            } else break;
        }
        while (dq.size()) {
            ll f = dq.front();
            if (dp[f] + i - f - 1 < arr[i]) {
                dq.pop_front();
            } else break;
        }

        dp[i] = arr[i] + 2 * S + i - idx - 1;
        if (dq.size()) dp[i] = min(dp[i], dp[dq.front()] + 2 * (S + i - dq.front() - 1));

        while (dq.size()) {
            ll b = dq.back();
            if (dp[b] - 2 * b > dp[i] - 2 * i) dq.pop_back();
            else break;
        }

        while (dq2.size()) {
            ll b = dq2.back();
            if (dp[b] - b > dp[i] - i) dq.pop_back();
            else break;
        }

        dq.push_back(i);
        dq2.push_back(i);
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