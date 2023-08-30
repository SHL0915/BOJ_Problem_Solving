#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
pii arr[105];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N);
    cin >> K;
    priority_queue<int, vector<int>, greater<>> pq;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a = arr[i].first, b = arr[i].second;
        while (pq.size()) {
            int t = pq.top();
            if (t <= a) pq.pop();
            else break;
        }
        pq.push(b);

        if (pq.size() > K) ans = 1;
    }

    cout << (ans ^ 1);
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