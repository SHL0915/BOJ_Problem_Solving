#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[500005];
vector<pii> cnt[1000005];
int ok[500005];

void solve() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (i == arr[i]) ok[i]++;
        cnt[i + arr[i]].push_back({min(i, arr[i]), max(i, arr[i])});
    }
    
    for (int i = 1; i <= N; i++) ok[i] += ok[i - 1];
    
    int val = 0;
    pii ans = {1, 1};
    
    for (int i = 1; i <= 2 * N; i++) {
        sort(cnt[i].begin(), cnt[i].end(), [&](pii a, pii b) {
            return a.second < b.second;
        });
        for (int j = 0; j < cnt[i].size(); j++) {
            int l = cnt[i][j].first, r = cnt[i][j].second;
            int now = j + 1 + ok[l - 1] + (ok[N] - ok[r]);
            if (val < now) {
                val = now;
                ans = {arr[l], arr[r]};
            }
        }
    }
    
    cout << ans.first << " " << ans.second;
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