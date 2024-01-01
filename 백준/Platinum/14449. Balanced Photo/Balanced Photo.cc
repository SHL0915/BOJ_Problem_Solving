#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
vector<int> v;
vector<int> lseg, rseg;

void update(int pos, int val, vector<int> &seg) {
    for (seg[pos += N] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r, vector<int> &seg) {
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
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    lseg.resize(2 * N + 5);
    rseg.resize(2 * N + 5);

    for (int i = 0; i < N; i++) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
        update(arr[i], 1, rseg);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        update(arr[i], -1, rseg);
        int l = query(arr[i] + 1, N, lseg);
        int r = query(arr[i] + 1, N, rseg);
        if (l > r) swap(l, r);
        if (2 * l < r) ans++;
        update(arr[i], 1, lseg);
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