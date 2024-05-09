#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, K;
ll arr[200005];

void solve() {
    cin >> N >> K;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            sum += arr[i];
            arr[i] *= -1;
        }
    }
    
    sort(arr, arr + N);
    
    int flag = 0;
    if (sum) cout << sum << '\n', K--, flag = 1;
    
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({sum + arr[0], 0});
    
    while (pq.size()) {
        if (!K) break;
        pii t = pq.top();
        pq.pop();
        ll v = t.first, now = t.second;
        if (!v && flag) flag = 0;
        else cout << v << '\n', K--;
        
        if (now < N - 1) {
            pq.push({v + arr[now + 1], now + 1});
            pq.push({v - arr[now] + arr[now + 1], now + 1});
        }
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