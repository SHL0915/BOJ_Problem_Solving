#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll T, K;
ll arr[4][4];

void solve() {
    cin >> T >> K;
    T--;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) cin >> arr[i][j];
    }
    
    ll l = 0, r = K;
    ll ans = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        
        vector<pair<pii, pii>> v;
        
        for (int i = 0; i < 4; i++) {
            int aa = 0, bb = 0, cc = 0;
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                int a = arr[i][j], b = arr[j][i];
                if (a == -1) a = m;
                if (b == -1) b = m;
                
                if (a > b) aa += 3;
                else if (a == b) aa++;
                
                bb += (a - b);
                cc += a;
            }
            v.push_back({{aa, bb},
                         {cc, -i}});
        }
        
        sort(v.begin(), v.end(), greater<>());
        int idx = -1;
        for (int i = 0; i < v.size(); i++) if (v[i].second.second == -T) idx = i;
        
        if (idx <= 1) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    
    if (ans == -1) cout << -1;
    else cout << ans;
    
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