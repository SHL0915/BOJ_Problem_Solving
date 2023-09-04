#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005], seg[200005];
int pos[100005];

void update(int pos, int val) {
    for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r) {
    int ret = 0;
    r++;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
        update(i, 1);
    }

    int a = 1, b = N, cnt = 0;
    while (cnt < N) {
        if (cnt % 2 == 0) {
            int now = pos[a];
            cout << query(1, now - 1) << '\n';
            update(now, 0);
            a++;
        } else {
            int now = pos[b];
            cout << query(now + 1, N) << '\n';
            update(now, 0);
            b--;
        }
        cnt++;
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