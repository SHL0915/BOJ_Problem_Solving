#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[3005];

ll ccw(pii a, pii b, pii c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N, [&](pii a, pii b) {
        if (a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });
    
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        vector<pii> v;
        for (int j = i + 1; j < N; j++) v.push_back(arr[j]);
        sort(v.begin(), v.end(), [&](pii a, pii b) {
            return ccw(arr[i], a, b) > 0;
        });
        
        pii psum = {0, 0};
        
        for (int j = 0; j < v.size(); j++) {
            ll x = v[j].first - arr[i].first, y = v[j].second - arr[i].second;
            tot += ccw({0, 0}, psum, {x, y});
            psum.first += x;
            psum.second += y;
        }
    }
    
    cout << tot / 2 << '.';
    if (tot % 2) cout << 5;
    else cout << 0;
    
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