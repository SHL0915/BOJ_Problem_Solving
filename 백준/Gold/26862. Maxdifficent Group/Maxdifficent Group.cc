#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
ll arr[100005];
pii l[100005], r[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    l[1] = {arr[1], arr[1]};

    for (int i = 2; i < N; i++) {
        l[i].first = max(l[i - 1].first + arr[i], arr[i]);
        l[i].second = min(l[i - 1].second + arr[i], arr[i]);
    }

    r[N - 1] = {arr[N], arr[N]};
    for (int i = N - 2; i >= 1; i--) {
        r[i].first = max(r[i + 1].first + arr[i + 1], arr[i + 1]);
        r[i].second = min(r[i + 1].second + arr[i + 1], arr[i + 1]);
    }

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans = max(ans, abs(l[i].first - r[i].second));
        ans = max(ans, abs(l[i].second - r[i].first));
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