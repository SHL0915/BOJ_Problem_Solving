#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K;
ll arr[1000005];
ll cnt[(1 << 20)];
ll dp[(1 << 20)], dp2[(1 << 20)];

void solve() {
    cin >> N >> K;

    ll nK = ((1 << 20) - 1) ^ K;
    vector<ll> v1, v2;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if ((arr[i] & K) == K) v1.push_back(arr[i] ^ K);
        ll nv = ((1 << 20) - 1) ^ arr[i];
        if ((K & arr[i]) == arr[i]) v2.push_back(arr[i] ^ K);
        cnt[arr[i]]++;
    }

    for (int i = 0; i < v1.size(); i++) dp[v1[i]]++;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (1 << 20); j++) if (j & (1 << i)) dp[j] += dp[j ^ (1 << i)];
    }

    ll ans1 = 0;
    for (int i = 0; i < v1.size(); i++) {
        ans1 += dp[((1 << 20) - 1) ^ v1[i]];
        ans1 -= v1[i] == 0;
    }

    ans1 /= 2;
    cout << ans1 << " ";

    for (int i = 0; i < v2.size(); i++) dp2[v2[i]]++;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (1 << 20); j++) if (j & (1 << i)) dp2[j] += dp2[j ^ (1 << i)];
    }

    ll ans2 = 0;
    for (int i = 0; i < v2.size(); i++) {
        ans2 += dp2[((1 << 20) - 1) ^ v2[i]];
        ans2 -= v2[i] == 0;
    }

    ans2 /= 2;
    cout << ans2 << " ";

    ll ans3 = 0;
    for (int i = 0; i < N; i++) ans3 += cnt[K ^ arr[i]];
    if (K == 0) ans3 -= N;

    ans3 /= 2;
    cout << ans3;

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