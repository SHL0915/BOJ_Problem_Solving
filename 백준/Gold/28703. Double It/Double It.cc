#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[200005];

void solve() {
    cin >> N;
    set<ll> s;
    for (int i = 0; i < N; i++) cin >> arr[i], s.insert(arr[i]);
    sort(arr, arr + N);
    ll ans = arr[N - 1] - arr[0];
    ll M = arr[N - 1];
    while (1) {
        ll f = *s.begin();
        if (f > 2 * M) break;
        ans = min(ans, *s.rbegin() - f);
        s.erase(f);
        s.insert(2 * f);
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