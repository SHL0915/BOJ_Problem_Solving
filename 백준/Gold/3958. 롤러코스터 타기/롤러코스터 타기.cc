#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int dp1[105][25005], dp2[25005], dp3[25005];
int prefix_val[25005];

void solve() {
    cin >> N;
    
    vector<pair<pii, int>> A;
    vector<pii> B;
    
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b) A.push_back({{a, b}, c});
        else {
            ll now = 1;
            while (1) {
                if (now * c > 25000) break;
                B.push_back({a * now, c * now});
                now *= 2;
            }
        }
    }
    
    memset(dp1, -0x3f, sizeof(dp1));
    
    dp1[0][0] = 0;
    
    for (int i = 0; i < A.size(); i++) {
        int a = A[i].first.first, b = A[i].first.second, c = A[i].second;
        
        int now = 0, t = 0;
        for (int j = 1;; j++) {
            int cost = a - (j - 1) * (j - 1) * b;
            if (cost <= 0) break;
            
            now += cost;
            t += c;
            
            if (t > 25000) break;
            
            for (int k = 0; k <= 25000; k++) {
                dp1[i + 1][k] = max(dp1[i + 1][k], dp1[i][k]);
                if (k < t) continue;
                dp1[i + 1][k] = max(dp1[i + 1][k], dp1[i][k - t] + now);
            }
        }
    }
    
    
    memset(dp2, -0x3f, sizeof(dp2));
    dp2[0] = 0;
    
    for (int i = 0; i < B.size(); i++) {
        int a = B[i].first, b = B[i].second;
        for (int j = 0; j <= 25000; j++) {
            dp3[j] = dp2[j];
            if (b > j) continue;
            dp3[j] = max(dp3[j], a + dp2[j - b]);
        }
        swap(dp2, dp3);
    }
    
    for (int i = 1; i <= 25000; i++) prefix_val[i] = max(prefix_val[i - 1], dp2[i]);
    
    cin >> Q;
    
    while (Q--) {
        int t;
        cin >> t;
        
        int ans = 0;
        for (int i = 0; i <= t; i++) ans = max(ans, dp1[A.size()][i] + prefix_val[t - i]);
        
        cout << ans << '\n';
    }
    
    
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