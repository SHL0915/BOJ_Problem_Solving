#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
pair<int, pii> arr[200005];
int min_seg[400005], max_seg[400005];
vector<int> ins[400005], del[400005];

void update_min(int pos, int val) {
    for (min_seg[pos += N] = val; pos > 0; pos >>= 1) min_seg[pos >> 1] = min(min_seg[pos], min_seg[pos ^ 1]);
    return;
}

void update_max(int pos, int val) {
    for (max_seg[pos += N] = val; pos > 0; pos >>= 1) max_seg[pos >> 1] = max(max_seg[pos], max_seg[pos ^ 1]);
    return;
}

int query_max(int l, int r) {
    r++;
    int ret = -INF;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, max_seg[l++]);
        if (r & 1) ret = max(ret, max_seg[--r]);
    }
    return ret;
}

int query_min(int l, int r) {
    r++;
    int ret = INF;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, min_seg[l++]);
        if (r & 1) ret = min(ret, min_seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, {b, c}};
        ins[i + b].push_back(i);
        del[i + c + 1].push_back(i);
    }
    
    memset(min_seg, INF, sizeof(min_seg));
    memset(max_seg, -INF, sizeof(max_seg));
    
    int ans = -1;
    for (int i = 1; i <= N; i++) {
        for (int a: ins[i]) {
            update_min(a, arr[a].first);
            update_max(a, arr[a].first);
        }
        for (int a: del[i]) {
            update_min(a, INF);
            update_max(a, -INF);
        }
        
        int now = arr[i].first, l = max(0, i - arr[i].second.second), r = max(0, i - arr[i].second.first);
        ans = max({ans, query_max(l, r) - now, now - query_min(l, r)});
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