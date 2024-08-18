#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Query {
    int l, r, idx;
} q[100005];

int N, Q, M, sqrtN;
int arr[100005];
vector<int> val;
int ans[100005], cnt[100005], max_cnt[100005];
int id_cnt[100005][355];

void push(int idx) {
    int now = arr[idx];
    max_cnt[cnt[now]]--;
    id_cnt[cnt[now]][now / sqrtN]--;
    cnt[now]++;
    max_cnt[cnt[now]]++;
    id_cnt[cnt[now]][now / sqrtN]++;
    M = max(M, cnt[now]);
}

void pop(int idx) {
    int now = arr[idx];
    if (M == cnt[now] && max_cnt[cnt[now]] == 1) M--;
    max_cnt[cnt[now]]--;
    id_cnt[cnt[now]][now / sqrtN]--;
    cnt[now]--;
    max_cnt[cnt[now]]++;
    id_cnt[cnt[now]][now / sqrtN]++;
}

int find_ans() {
    int now = N / sqrtN;
    for (int i = now; i >= 0; i--) {
        if (!id_cnt[M][i]) continue;
        for (int j = (i + 1) * sqrtN;; j--) {
            if (cnt[j] == M) return j;
        }
    }
}


void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> arr[i], val.push_back(arr[i]);

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 1; i <= N; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin();

    sqrtN = sqrt(N);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r, i};
    }

    sort(q, q + Q, [&](Query a, Query b) {
        if (a.l / sqrtN == b.l / sqrtN) return a.r < b.r;
        else return a.l < b.l;
    });

    int l = q[0].l, r = q[0].r;
    for (int i = l; i <= r; i++) push(i);
    ans[q[0].idx] = val[find_ans()];

    for (int i = 1; i < Q; i++) {
        int nl = q[i].l, nr = q[i].r, idx = q[i].idx;
        while (l > nl) push(--l);
        while (r < nr) push(++r);
        while (l < nl) pop(l++);
        while (r > nr) pop(r--);
        ans[idx] = val[find_ans()];
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