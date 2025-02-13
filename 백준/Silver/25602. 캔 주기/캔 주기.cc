#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
int arr[55], ans, R[55][55], M[55][55];

void BackTracking(vector<pii> &v, int k) {
    if (!k) {
        int cnt[5] = {0};
        int now = 0;
        for (int i = 0; i < v.size(); i++) {
            int a = v[i].first, b = v[i].second;
            now += R[i][a], now += M[i][b];
            cnt[a]++, cnt[b]++;
        }
        for (int i = 0; i < N; i++) {
            if (cnt[i] > arr[i]) return;
        }
        ans = max(ans, now);
        return;
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                v.push_back({i, j});
                BackTracking(v, k - 1);
                v.pop_back();
            }
        }
    }
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) cin >> R[i][j];
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) cin >> M[i][j];
    }
    
    vector<pii> v;
    BackTracking(v, K);
    
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