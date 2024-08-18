#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K, B, sqrtN;
int arr[200005];
pair<pii, int> q[200005];
int ans[200005];
deque<int> dq[200005];
int sCnt[355], cnt[200005];

void push(int idx) {
    int now = arr[idx];

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        sCnt[v / sqrtN]--;
        cnt[v]--;
    }

    if (dq[now].empty()) dq[now].push_back(idx);
    else {
        if (idx < dq[now].front()) dq[now].push_front(idx);
        else dq[now].push_back(idx);
    }

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        sCnt[v / sqrtN]++;
        cnt[v]++;
    }

    return;
}

void pop(int idx) {
    int now = arr[idx];
    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        sCnt[v / sqrtN]--;
        cnt[v]--;
    }

    if (idx == dq[now].back()) dq[now].pop_back();
    else dq[now].pop_front();

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        sCnt[v / sqrtN]++;
        cnt[v]++;
    }

    return;
}

int query() {
    int now = N / sqrtN + 1;

    for (int i = now; i >= 0; i--) {
        if (sCnt[i]) {
            for (int j = (i + 1) * sqrtN;; j--) {
                if (cnt[j]) return j;
            }
        }
    }

    return 0;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {{l, r}, i};
    }

    while (B * B <= M) B++;
    B--;
    sqrtN = sqrt(N);

    sort(q, q + M, [&](pair<pii, int> a, pair<pii, int> b) {
        if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
        else return a.first.first / B < b.first.first / B;
    });

    int l = q[0].first.first, r = q[0].first.second;
    for (int i = l; i <= r; i++) push(i);
    ans[q[0].second] = query();

    for (int i = 1; i < M; i++) {
        int nl = q[i].first.first, nr = q[i].first.second, id = q[i].second;
        while (l > nl) push(--l);
        while (r < nr) push(++r);
        while (l < nl) pop(l++);
        while (r > nr) pop(r--);
        ans[id] = query();
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