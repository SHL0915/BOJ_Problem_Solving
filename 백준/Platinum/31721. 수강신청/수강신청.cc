#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, ans;
pii arr[100005];

void solve() {
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= b)ans++;
        else pq.push(a);
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (pq.size()) ans++, pq.pop();
        cnt += M - 1;
        while (pq.size()) {
            if (pq.top() > cnt) break;
            else {
                cnt -= pq.top();
                pq.pop();
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