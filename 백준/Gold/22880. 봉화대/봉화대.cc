#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N;
int arr[500005];
vector<pii> v;
vector<ll> val;
ll dp[500005];

ll DP(int now) {
    if (now == val.size()) return 1;
    ll &ret = dp[now];
    if (ret != -1) return ret;
    ret = 0;

    ret += ((val[now] + 1) * DP(now + 1)) % mod;
    ret %= mod;

    return ret;
}


void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    v.push_back({arr[0], 0});
    for (int i = 1; i < N; i++) {
        if (arr[i] > v.back().first) {
            val.push_back(i - v.back().second);
            v.push_back({arr[i], i});
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << DP(0);

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