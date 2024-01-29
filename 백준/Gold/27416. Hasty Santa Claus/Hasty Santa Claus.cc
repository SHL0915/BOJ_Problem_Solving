#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector<pii> arr[35];
int ans[1005];

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back({b, i});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 1; i <= 31; i++) {
        for (pii a: arr[i]) pq.push(a);
        for (int j = 0; j < K; j++) {
            if (pq.empty()) break;
            pii t = pq.top();
            pq.pop();
            ans[t.second] = i;
        }
    }

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