#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[250005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr + N, [&](pii a, pii b) {
        return (a.first + a.second) < (b.first + b.second);
    });
    
    priority_queue<ll> pq;
    
    ll now = 0;
    for (int i = 0; i < N; i++) {
        if (now + arr[i].second <= arr[i].first + arr[i].second) {
            pq.push(arr[i].second);
            now += arr[i].second;
        } else {
            if (arr[i].second < pq.top()) {
                now -= pq.top();
                pq.pop();
                now += arr[i].second;
                pq.push(arr[i].second);
            }
        }
    }
    
    cout << pq.size() << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}