#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt;
ll ans;
vector<int> tree[200005];
ll arr[200005], dp[200005][2];

ll tree_dp(int node, int type) {
    ll &ret = dp[node][type];
    if (ret != -1) return ret;
    ret = 0;

    vector<ll> a, b, c;
    ll add = -0x3f3f3f3f3f3f3f3fLL;
    for (int next: tree[node]) {
        ll f = tree_dp(next, 0), s = tree_dp(next, 1), m = max(f, s);
        if (s <= 0) add = max(add, f);
        b.push_back(f);
        if (s > 0) c.push_back(s);
        a.push_back(m);
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());

    if (type == 0) {
        if (a.size()) {
            ret = max(ret, a.front());
            if (a.size() > 1) ans = max(ans, a[0] + a[1]);
        }
    } else {
        ll sum = 0;
        for (ll e: c) sum += e;
        ret = sum + arr[node];
        ans = max(ans, ret + add);
    }

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int p;
        cin >> p;
        if (p != -1) tree[p].push_back(i);
    }

    memset(dp, -1, sizeof(dp));
    tree_dp(1, 0);
    tree_dp(1, 1);

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