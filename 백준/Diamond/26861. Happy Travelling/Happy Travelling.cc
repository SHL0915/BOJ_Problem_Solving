#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 2e9;

int N, K, D;
int arr[100005], T[100005];
int ans[100005];
int seg[4 * 100005], lazy[4 * 100005];
deque<pair<int, pii>> dq[1205];

void update_lazy(int n, int s, int e) {
    if (lazy[n] != -INF) {
        seg[n] = max(seg[n], lazy[n]);
        if (s != e) {
            lazy[n * 2] = max(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = max(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = -INF;
    }
    return;
}

void update(int n, int s, int e, int l, int r, int v) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        lazy[n] = max(lazy[n], v);
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, l, r, v);
    update(n * 2 + 1, m + 1, e, l, r, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
    return;
}

int query(int n, int s, int e, int l, int r) {
    update_lazy(n, s, e);
    if (l > e || r < s) return -INF;
    if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return max(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

int find_val(int idx) {
    if (K >= 1105) return query(1, 1, N, idx, idx) + arr[idx];
    else {
        int ret = -INF;
        for (int i = 0; i < K; i++) {
            while (!dq[i].empty()) {
                pair<int, pii> f = dq[i].front();
                int pos = f.second.first, len = f.second.second, v = f.first - (pos / K) * D;
                if (pos + len < idx) {
                    dq[i].pop_front();
                    continue;
                } else {
                    ret = max(ret, v - ((idx - pos) / K) * D + arr[idx]);
                    break;
                }
            }
        }
        return ret;
    }
}

void update_val(int idx) {
    if (K >= 1105) {
        int pos = idx, cnt = 0;
        while (pos <= idx + T[idx]) {
            int l = pos, r = min(idx + T[idx], pos + K - 1);
            update(1, 1, N, l, r, ans[idx] - cnt * D);
            cnt++;
            pos += K;
        }
    } else {
        int pos = idx % K;
        int val = ans[idx] + (idx / K) * D;
        while (!dq[pos].empty()) {
            pair<ll, pii> b = dq[pos].back();
            int v = b.first;
            if (v <= val) dq[pos].pop_back();
            else break;
        }
        dq[pos].push_back({val, {idx, T[idx]}});
    }
    return;
}

void solve() {
    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i < N; i++) cin >> T[i];

    fill(seg, seg + 4 * 100005, -INF);
    fill(lazy, lazy + 4 * 100005, -INF);

    update(1, 1, N, 1, 1, arr[1]);
    ans[1] = arr[1];
    update_val(1);

    for (int i = 2; i < N; i++) {
        ans[i] = find_val(i);
        update_val(i);
    }

    cout << find_val(N);

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