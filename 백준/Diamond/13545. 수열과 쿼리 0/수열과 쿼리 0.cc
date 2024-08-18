#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, B, sqrtN;
int arr[100505], ans[100505], scnt[100505], cnt[100505];
deque<int> dq[200005];
pair<pii, int> q[100005];

void push(int idx) {
    int now = arr[idx] + N;

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        scnt[v / sqrtN]--;
        cnt[v]--;
    }

    if (dq[now].empty() || idx > dq[now].back()) dq[now].push_back(idx);
    else dq[now].push_front(idx);

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        scnt[v / sqrtN]++;
        cnt[v]++;
    }

    return;
}

void pop(int idx) {
    int now = arr[idx] + N;

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        scnt[v / sqrtN]--;
        cnt[v]--;
    }

    if (idx == dq[now].back()) dq[now].pop_back();
    else dq[now].pop_front();

    if (dq[now].size() >= 2) {
        int v = dq[now].back() - dq[now].front();
        scnt[v / sqrtN]++;
        cnt[v]++;
    }

    return;
}

int query() {
    int now = N / sqrtN;
    for (int i = now; i >= 0; i--) {
        if (scnt[i]) {
            for (int j = (i + 1) * sqrtN;; j--) {
                if (cnt[j]) return j;
            }
        }
    }
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i], arr[i] += arr[i - 1];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {{l - 1, r}, i};
    }

    while (B * B <= M) B++;
    B--;
    sqrtN = sqrt(N);

    sort(q, q + M, [&](pair<pii, int> a, pair<pii, int> b) {
        if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
        return a.first.first / B < b.first.first / B;
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