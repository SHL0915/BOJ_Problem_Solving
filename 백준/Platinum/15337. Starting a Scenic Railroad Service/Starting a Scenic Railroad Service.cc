#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 100005;

int N;
pii arr[200005];
int psum[sz], seg[sz * 2];

void update(int pos, int v) {
    for (seg[pos += sz] += v; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
        psum[arr[i].first]++;
        psum[arr[i].second]--;
        update(arr[i].first, 1);
    }

    int a = 0, b = 0;
    sort(arr, arr + N);
    for (int i = 1; i <= sz; i++) psum[i] += psum[i - 1], a = max(a, psum[i]);

    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        while (pq.size()) {
            int t = pq.top();
            if (-t > arr[i].first) break;
            else pq.pop();
        }

        int q = query(arr[i].first, arr[i].second - 1);
        b = max(b, q + (int) pq.size());

        pq.push(-arr[i].second);
        update(arr[i].first, -1);
    }

    cout << b << " " << a;
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