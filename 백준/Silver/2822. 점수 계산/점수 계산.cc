#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<pii> arr;

void solve() {
    for (int i = 1; i <= 8; i++) {
        int a;
        cin >> a;
        arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end(), greater<>());
    
    vector<int> v;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += arr[i].first;
        v.push_back(arr[i].second);
    }
    sort(v.begin(), v.end());
    
    cout << ans << '\n';
    for (int i = 0; i < 5; i++) cout << v[i] << ' ';
    
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