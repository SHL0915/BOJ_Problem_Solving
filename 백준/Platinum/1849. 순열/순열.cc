#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005], ans[100005];
int seg[200005];

void update(int pos, int v) {
    for (seg[pos += N] += v; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) update(i, 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int l = 1, r = N, ok = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            int q = query(1, m);
            if (q >= arr[i] + 1) ok = m, r = m - 1;
            else l = m + 1;
        }
        ans[ok] = i;
        update(ok, -1);
    }
    
    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
    
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