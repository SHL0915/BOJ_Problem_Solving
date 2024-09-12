#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, W;
pair<pii, int> arr[100005];

void solve() {
    cin >> N >> W;
    
    vector<pair<pii, int>> small, large;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i + 1;
        if (arr[i].first.first > W / 2) large.push_back(arr[i]);
        else small.push_back(arr[i]);
    }
    
    sort(large.begin(), large.end());
    
    sort(small.begin(), small.end(), [&](pair<pii, int> a, pair<pii, int> b) {
        return a.first.second * b.first.first > a.first.first * b.first.second;
    });
    
    vector<ll> wsum(N + 1, 0), csum(N + 1, 0);
    
    for (int i = 1; i <= small.size(); i++) {
        pair<pii, int> now = small[i - 1];
        wsum[i] = wsum[i - 1] + now.first.first;
        csum[i] = csum[i - 1] + now.first.second;
    }
    
    int ptr = 0;
    for (int i = 1; i <= small.size(); i++) {
        if (2 * wsum[i] <= 3 * W) ptr = i;
    }
    
    pii choose = {csum[ptr], 0};
    
    for (int i = 1; i <= large.size(); i++) {
        pair<pii, int> now = large[i - 1];
        ll val = now.first.second;
        while (ptr >= 0) {
            if (2 * (wsum[ptr] + now.first.first) > 3 * W) ptr--;
            else break;
        }
        if (ptr < 0) continue;
        val += csum[ptr];
        if (val > choose.first) choose = {val, i};
    }
    
    vector<int> ans;
    
    ll tot = 0;
    if (choose.second) {
        ans.push_back(large[choose.second - 1].second);
        tot += large[choose.second - 1].first.first;
    }
    
    for (int i = 0; i < small.size(); i++) {
        pair<pii, int> now = small[i];
        if (2 * (tot + now.first.first) > 3 * W) break;
        tot += now.first.first;
        ans.push_back(now.second);
    }
    
    cout << ans.size() << '\n';
    for (int i: ans) cout << i << " ";
    cout << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}