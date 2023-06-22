#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct planet {
    ll x, y, z;
};

int N;
planet arr[100005];

ll sqrdist(planet a, planet b);

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].x >> arr[i].y >> arr[i].z;
    
    ll ans = 4000000000000000000LL;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) ans = min(ans, sqrdist(arr[i], arr[j]));
    }
    
    cout << sqrt(ans);
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

ll sqrdist(planet a, planet b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    ll dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}