#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pair<pii, pii> arr[5005];
ll dp[5005];

int dist(int i, int j) {
    ll dx = arr[i].second.first - arr[j].second.first;
    ll dy = arr[i].second.second - arr[j].second.second;
    return abs(dx) + abs(dy);
}

ll DP(int now) {
    ll &ret = dp[now];
    if (~ret) return ret;
    ret = 0;
    ll t = arr[now].first.second;
    
    for (int i = now + 1; i <= N; i++) {
        ll d = dist(now, i);
        if (d + t > arr[i].first.second) continue;
        ret = max(ret, arr[i].first.second - max(arr[i].first.first, (d + t)) + DP(i));
    }
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i].second = {x, y};
    }
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i].first = {a, b};
    }
    sort(arr, arr + N + 1, [&](pair<pii, pii> a, pair<pii, pii> b) {
        return a.first.second < b.first.second;
    });
    
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