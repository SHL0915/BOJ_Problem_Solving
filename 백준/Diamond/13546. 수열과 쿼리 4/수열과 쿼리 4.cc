#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, M, B;
ll arr[100005];
deque<int> cnt[100005];
int seg[200005];
pair<pii, int> q[100005];
int ans[100005];

void push(int a);

void pop(int a);

void update(int pos, int val);

int query(int l, int r);

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cin >> M;
    while (B * B <= N) B++;
    B--;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {{l, r}, i};
    }

    sort(q, q + M, [&](pair<pii, int> a, pair<pii, int> b) {
        if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
        return a.first.first / B < b.first.first / B;
    });

    int l = q[0].first.first, r = q[0].first.second;
    for (int i = l; i <= r; i++) push(i);

    ans[q[0].second] = query(1, K);

    for (int i = 1; i < M; i++) {
        int nl = q[i].first.first, nr = q[i].first.second;
        int idx = q[i].second;

        while (l > nl) push(--l);
        while (r < nr) push(++r);
        while (l < nl) pop(l++);
        while (r > nr) pop(r--);

        ans[idx] = query(1, K);
    }

    for (int i = 0; i < M; i++) cout << ans[i] << '\n';
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

void push(int a) {
    int now = arr[a];
    if (cnt[now].size() == 0) cnt[now].push_back(a);
    else if (a < cnt[now].front()) cnt[now].push_front(a);
    else cnt[now].push_back(a);
    if (cnt[now].size() >= 2) update(now, cnt[now].back() - cnt[now].front());
    return;
}

void pop(int a) {
    int now = arr[a];
    if (a == cnt[now].front()) cnt[now].pop_front();
    else cnt[now].pop_back();

    if (cnt[now].size() < 2) update(now, 0);
    else update(now, cnt[now].back() - cnt[now].front());
    return;
}

void update(int pos, int val) {
    for (seg[pos += K] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += K, r += K; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}