#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int arr[1000005];
int dp[1000005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;
        deque<pair<pii, int>> dq;
        dp[0] = 0;
        dq.push_front({{0, arr[0]}, 0});

        for (int i = 1; i < N; i++) {
            while (dq.size()) {
                pair<pii, int> b = dq.back();
                if (b.second < i - k) dq.pop_back();
                else break;
            }
            pair<pii, int> b = dq.back();
            if (b.first.second > arr[i]) dp[i] = b.first.first;
            else dp[i] = b.first.first + 1;
            
            while (dq.size()) {
                pair<pii, int> f = dq.front();
                if (dp[i] > f.first.first || (dp[i] == f.first.first && arr[i] <= f.first.second)) break;
                else dq.pop_front();
            }
            dq.push_front({{dp[i], arr[i]}, i});
        }

        cout << dp[N - 1] << '\n';
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