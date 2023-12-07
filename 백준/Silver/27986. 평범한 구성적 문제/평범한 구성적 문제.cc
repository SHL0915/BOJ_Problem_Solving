#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
pii arr[1005];
int ans[1005];

void solve() {
    cin >> N >> M;
    int len = N;
    for (int i = 0; i < M; i++) {
        cin >> arr[i].first >> arr[i].second;
        len = min(len, arr[i].second - arr[i].first + 1);
    }
    sort(arr, arr + M, [&](pii a, pii b) {
        return a.second - a.first < b.second - b.first;
    });
    
    for (int i = 0; i < M; i++) {
        int l = arr[i].first, r = arr[i].second;
        set<int> s;
        for (int j = l; j <= r; j++) {
            if (ans[j] != 0) s.insert(ans[j]);
        }
        
        set<int> cand;
        for (int j = 1; j <= len; j++) cand.insert(j);
        for (int j: s) cand.erase(j);
        
        for (int j = l; j <= r; j++) {
            if (ans[j]) continue;
            else {
                if (cand.size()) {
                    ans[j] = *cand.begin();
                    cand.erase(ans[j]);
                } else continue;
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (ans[i]) cout << ans[i] << " ";
        else cout << 1 << " ";
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