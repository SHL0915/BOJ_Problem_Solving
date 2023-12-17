#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, D;
pii arr[100005];

void solve() {
    cin >> N;
    vector<int> val;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
    }

    cin >> D;
    sort(arr, arr + N);
    priority_queue<int> pq;
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        pq.push(arr[i].second);
        while (pq.size()) {
            int t = pq.top();
            if (t > arr[i].first + D) pq.pop();
            else break;
        }
        ans = max(ans, (int) pq.size());
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