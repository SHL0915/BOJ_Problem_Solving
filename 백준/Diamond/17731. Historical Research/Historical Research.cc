#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Query {
    int l, r, idx;
} q[100005];

int N, Q, sqrtN;
ll arr[100005], cnt[100005];
ll ans[100005];
vector<ll> val;
map<ll, int> m[355];

void push(int idx) {
    ll now = arr[idx];
    m[now / sqrtN][cnt[now] * val[now]]--;
    if (m[now / sqrtN][cnt[now] * val[now]] == 0) m[now / sqrtN].erase(cnt[now] * val[now]);
    cnt[now]++;
    m[now / sqrtN][cnt[now] * val[now]]++;
}

void pop(int idx) {
    ll now = arr[idx];
    m[now / sqrtN][cnt[now] * val[now]]--;
    if (m[now / sqrtN][cnt[now] * val[now]] == 0) m[now / sqrtN].erase(cnt[now] * val[now]);
    cnt[now]--;
    m[now / sqrtN][cnt[now] * val[now]]++;
}

ll find_ans() {
    int now = N / sqrtN;
    ll ans = 0;
    for (int i = now; i >= 0; i--) {
        if (m[i].empty()) continue;
        if (m[i].rbegin()->second > 0) ans = max(ans, m[i].rbegin()->first);
    }
    return ans;
}

void solve() {
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) cin >> arr[i], val.push_back(arr[i]);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 1; i <= N; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin();

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r, i};
    }

    sqrtN = sqrt(N);
    sort(q, q + Q, [&](Query a, Query b) {
        if (a.l / sqrtN == b.l / sqrtN) return a.r < b.r;
        else return a.l < b.l;
    });

    int l = q[0].l, r = q[0].r;
    for (int i = l; i <= r; i++) push(i);

    ans[q[0].idx] = find_ans();

    for (int i = 1; i < Q; i++) {
        int nl = q[i].l, nr = q[i].r, idx = q[i].idx;
        while (l > nl) push(--l);
        while (r < nr) push(++r);
        while (l < nl) pop(l++);
        while (r > nr) pop(r--);
        ans[idx] = find_ans();
    }

    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';

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