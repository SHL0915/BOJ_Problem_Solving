#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pair<pii, int> arr[1005];
ll ldp[1005], rdp[1005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    sort(arr, arr + N);

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ldp[i] = arr[i].second;
        rdp[i] = arr[i].second;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j].first.second < arr[i].first.second) ldp[i] = max(ldp[i], arr[i].second + ldp[j]);
            if (arr[j].first.second > arr[i].first.second) rdp[i] = max(rdp[i], arr[i].second + rdp[j]);
        }

        ans = max({ans, ldp[i], rdp[i]});
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