#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[1000005];
ll prefix_happy[1000005], prefix_sad[1000005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    
    prefix_happy[0] = 1e9 + 5;
    for (int i = 1; i <= N; i++) {
        if (arr[i].first) prefix_happy[i] = min(prefix_happy[i - 1], arr[i].first);
        else prefix_happy[i] = prefix_happy[i - 1];
        if (arr[i].second) prefix_sad[i] = max(prefix_sad[i - 1], arr[i].second);
        else prefix_sad[i] = prefix_sad[i - 1];
    }
    
    ll a = 0, b = 1e9 + 5;
    if (arr[N].first) a = max(a, arr[N].first);
    if (arr[N].second) b = min(b, arr[N].second);
    
    for (int i = N - 1; i >= 1; i--) {
        if ((prefix_happy[i] >= a) && (prefix_sad[i] <= b)) {
            cout << i;
            return;
        }
        if (arr[i].first) a = max(a, arr[i].first);
        if (arr[i].second) b = min(b, arr[i].second);
    }
    
    cout << -1;
    
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