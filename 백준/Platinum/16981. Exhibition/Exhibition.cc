#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
pii arr[100005];
int frame[100005];

void solve() {
    cin >> N >> M;
    priority_queue<pii> pq;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
        pq.push({arr[i].second, arr[i].first});
    }
    for (int i = 0; i < M; i++) cin >> frame[i];
    sort(frame, frame + M);
    
    int ans = 0;
    for (int i = M - 1; i >= 0; i--) {
        while (pq.size()) {
            auto t = pq.top();
            pq.pop();
            if (t.second > frame[i]) continue;
            else {
                ans++;
                break;
            }
        }
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