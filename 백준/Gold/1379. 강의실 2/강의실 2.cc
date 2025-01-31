#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<pair<pii, int>> arr;
int ans[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({{b, c}, a});
    }
    sort(arr.begin(), arr.end());
    
    int l = 1, r = N, ok = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (int i = 0; i < m; i++) pq.push(0);
        
        int flag = 0;
        for (int i = 0; i < arr.size(); i++) {
            int a = arr[i].first.first, b = arr[i].first.second;
            if (pq.top() > a) {
                flag = 1;
                break;
            }
            pq.pop();
            pq.push(b);
        }
        
        if (flag) l = m + 1;
        else {
            ok = m;
            r = m - 1;
        }
    }
    
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 1; i <= ok; i++) pq.push({0, i});
    
    for (int i = 0; i < arr.size(); i++) {
        int a = arr[i].first.first, b = arr[i].first.second;
        ans[arr[i].second] = pq.top().second;
        pq.pop();
        pq.push({b, ans[arr[i].second]});
    }
    
    cout << ok << '\n';
    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
    
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