#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[300005];
ll val[300005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    for (ll i = 1; i <= N; i++) val[i] = i * i - (i - 1) * (i - 1);

    ll ans = 0;

    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;
    pq.push({arr[0], {arr[0], 1}});

    for (int i = 1; i < N; i++) {
        auto t = pq.top();
        pq.pop();
        ll a = t.first, b = t.second.first, c = t.second.second;
        ans += a;
        pq.push({b * val[c + 1], {b, c + 1}});
        ans += arr[i];
        pq.push({arr[i] * val[2], {arr[i], 2}});
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