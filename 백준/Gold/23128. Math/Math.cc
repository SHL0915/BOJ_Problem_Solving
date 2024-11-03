#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll cnt[1000005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        cnt[a]++;
    }
    
    ll ans = 0;
    
    for (ll i = 1; i <= 1000000; i++) {
        if (!cnt[i]) continue;
        for (ll j = i + 1;; j++) {
            ll now = j * j - i * i;
            if (now > 1000000) break;
            if (cnt[now]) ans++;
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