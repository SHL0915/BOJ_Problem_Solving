#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
pii arr[300005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N);
    priority_queue<int, vector<int>, greater<>> pq;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        while (pq.size()) {
            int t = pq.top();
            if (t < arr[i].first - M) pq.pop();
            else if (t >= arr[i].first - M && t <= arr[i].first) {
                pq.pop();
                ans++;
                break;
            } else break;
        }
        pq.push(arr[i].first + arr[i].second);
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