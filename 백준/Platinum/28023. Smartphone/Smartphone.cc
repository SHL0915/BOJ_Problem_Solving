#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, K;
pair<pii, ll> arr[300005];

void solve() {
    cin >> N >> K;
    vector<ll> v;
    for (int i = 0; i < N; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        arr[i] = {{l, r}, c};
        v.push_back(l);
        v.push_back(r);
    }
    sort(arr, arr + N);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v.push_back(K + 1);
    
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    ll now = 0, ans = 0;
    
    for (int i = 0; i < N; i++) {
        ll s = arr[i].first.first;
        while (pq.size()) {
            auto t = pq.top();
            if (now < s) {
                pq.pop();
                ll max_time = s - 1;
                ll can_use = min(t.first - now + 1, t.second);
                ll val = min(can_use, max_time - now + 1);
                if (!val) continue;
                
                now += val;
                ans += val;
                
                if (val == t.second) continue;
                else pq.push({t.first, t.second - val});
            } else break;
        }
        
        now = max(now, s);
        
        while (pq.size()) {
            auto t = pq.top();
            if (t.first < now) pq.pop();
            else break;
        }
        
        pq.push({arr[i].first.second, arr[i].second});
    }
    
    ll s = K + 1;
    while (pq.size()) {
        auto t = pq.top();
        if (now < s) {
            pq.pop();
            ll max_time = s - 1;
            ll can_use = min(t.first - now + 1, t.second);
            ll val = min(can_use, max_time - now + 1);
            if (!val) continue;
            
            now += val;
            ans += val;
            
            if (val == t.second) continue;
            else pq.push({t.first, t.second - val});
        } else break;
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