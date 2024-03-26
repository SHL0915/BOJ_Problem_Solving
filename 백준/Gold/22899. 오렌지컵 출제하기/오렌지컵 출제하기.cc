#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K;
ll arr[100005];
ll A[100005];
set<int> s;
priority_queue<ll> pq[100005];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (pq[arr[i]].size() == 0) s.insert(arr[i]);
        pq[arr[i]].push(-A[i]);
    }
    
    priority_queue<ll> pool;
    priority_queue<ll> ans;
    
    ll tot = 0, cnt = 0;
    
    for (int i = 1; i <= N; i++) {
        vector<int> v;
        for (int a: s) {
            ll t = pq[a].top();
            if (pq[a].size() == 0) v.push_back(a);
            pq[a].pop();
            pool.push(t);
        }
        for (int a: v) s.erase(a);
        
        while (pool.size()) {
            ll t = -pool.top();
            if (ans.size() < K) {
                tot += t;
                ans.push(t);
                pool.pop();
            } else {
                if (ans.top() <= t) break;
                else {
                    tot -= ans.top();
                    ans.pop();
                    ans.push(t);
                    tot += t;
                    pool.pop();
                }
            }
        }
        
        
        if (ans.size() < K) cout << -1 << " ";
        else cout << tot << " ";
        
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