#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 2e9;

int N, K, D;
int arr[100005], T[100005];
int ans[100005];
int seg[2 * 100005];
deque<pair<int, pii>> dq[1205];

void update(int pos, int v) {
    pos += 100005;
    for (seg[pos] = max(seg[pos], v); pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = -INF;
    for (l += 100005, r += 100005; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

int find_val(int idx) {
    if (K >= 505) return query(idx, N) + arr[idx];
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
    if (K >= 505) {
        int pos = idx, cnt = 0;
        while (pos <= idx + T[idx]) {
            int r = min(idx + T[idx], pos + K - 1);
            update(r, ans[idx] - cnt * D);
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

    fill(seg, seg + 2 * 100005, -INF);

    update(1, arr[1]);
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