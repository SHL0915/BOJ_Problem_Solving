#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K;
int pos[100005];
int seg[200005];
pair<int, pii> arr[100005];

void update(int idx, int val) {
    idx += K;
    for (seg[idx] = min(seg[idx], val); idx > 0; idx >>= 1) seg[idx >> 1] = min(seg[idx], seg[idx ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = INF;
    for (l += K, r += K; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, seg[l++]);
        if (r & 1) ret = min(ret, seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
        pos[i] = arr[i].first;
    }
    sort(arr + 1, arr + 1 + K);
    sort(pos + 1, pos + 1 + K);
    
    memset(seg, INF, sizeof(seg));
    update(0, 0);
    
    for (int i = 1; i <= K; i++) {
        int now = arr[i].first, len = arr[i].second.first, cost = arr[i].second.second;
        int l = max(0, now - len);
        int r = min(N, now + len);
        int pre = lower_bound(pos, pos + K + 1, l) - pos;
        pre = max(0, pre - 1);
        int next = upper_bound(pos, pos + K + 1, r) - pos;
        next--;
        int q = query(pre, K);
        update(next, q + cost);
    }
    
    cout << query(K, K);
    
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