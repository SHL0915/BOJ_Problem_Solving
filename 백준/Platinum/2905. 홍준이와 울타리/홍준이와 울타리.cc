#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, X;
int arr[1000005], h[1000005];

void update(int pos, int v, vector<int> &seg) {
    for (seg[pos += N] = v; pos > 0; pos >>= 1) seg[pos >> 1] = min(seg[pos], seg[pos ^ 1]);
}

int query(int l, int r, vector<int> &seg) {
    r++;
    int ret = 1e9;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, seg[l++]);
        if (r & 1) ret = min(ret, seg[--r]);
    }
    return ret;
}


void solve() {
    cin >> N >> X;
    vector<int> min_seg(2 * N + 5), max_seg(2 * N + 5);
    for (int i = 1; i <= N; i++) cin >> arr[i], update(i, arr[i], min_seg);

    for (int i = 1; i <= N; i++) {
        if (i + X - 1 > N) break;
        int v = query(i, i + X - 1, min_seg);
        int q = -query(i, i, max_seg);
        update(i, -max(v, q), max_seg);
    }

    ll a = 0;
    for (int i = 1; i <= N; i++) {
        h[i] = -query(max(1, i - X + 1), i, max_seg);
        a += (arr[i] - h[i]);
    }

    multiset<int> ms;

    for (int i = 1; i <= X; i++) ms.insert(arr[i]);

    int ans = 1, v = *ms.begin(), idx = X;
    for (int i = X + 1; i <= N; i++) {
        int l = arr[i - X], r = arr[i];

        ms.erase(ms.find(l));
        ms.insert(r);

        int now = *ms.begin();
        if (now > v) {
            v = now;
            ans++;
            idx = i;
        } else if (now == v) {
            if (i - idx == X) ans++, idx = i;
        } else {
            v = now;
            if (idx == i - 1) continue;
            else {
                ans++;
                idx = i - 1;
            }
        }
    }

    if (idx != N) ans++;

    cout << a << '\n' << ans;

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