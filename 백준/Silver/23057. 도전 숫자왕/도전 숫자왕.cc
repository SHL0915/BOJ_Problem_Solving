#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[25];

void solve() {
    cin >> N;
    ll tot = 0;
    for (int i = 0; i < N; i++) cin >> arr[i], tot += arr[i];

    vector<ll> v;
    for (int i = 1; i < (1 << N); i++) {
        ll now = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) now += arr[j];
        }
        v.push_back(now);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << tot - v.size();

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