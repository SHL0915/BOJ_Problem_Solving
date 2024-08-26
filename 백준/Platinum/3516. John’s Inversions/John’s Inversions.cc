#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[100005];
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

    vector<int> v;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second, v.push_back(arr[i].second);
    sort(arr, arr + N);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        arr[i].second = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin() + 1;
        ans += query(arr[i].second + 1, N);
        update(arr[i].second, 1);
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