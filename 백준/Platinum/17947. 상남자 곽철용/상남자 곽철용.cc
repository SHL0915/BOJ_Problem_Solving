#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int cnt[400005];

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= 4 * N; i++) cnt[i % K]++;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a % K]--;
        cnt[b % K]--;
    }
    
    int a, b;
    cin >> a >> b;
    int score = abs(a % K - b % K);
    cnt[a % K]--;
    cnt[b % K]--;
    
    int ans = 0;
    
    priority_queue<int, vector<int>, greater<>> pq, cand;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            if (cand.size() && i - cand.top() > score) {
                pq.push(i);
                cand.pop();
                ans++;
            } else {
                if (pq.size() && i - pq.top() > score) {
                    pq.push(i);
                    pq.pop();
                    ans++;
                } else cand.push(i);
            }
        }
    }
    
    cout << min(M - 1, ans);
    
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