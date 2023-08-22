#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, Q, B, sz;
int arr[100005];
deque<int> cnt[100005];
int ccnt[100505];
int bucket[100505];
pair<int, pii> q[100005];
int ans[100005];

void push(int a) {
    int num = arr[a];
    if (cnt[num].size() >= 2) {
        int val = cnt[num].back() - cnt[num].front();
        ccnt[val]--;
        bucket[val / sz]--;
    }

    if (cnt[num].size() == 0) cnt[num].push_back(a);
    else if (a < cnt[num].front()) cnt[num].push_front(a);
    else cnt[num].push_back(a);

    if (cnt[num].size() >= 2) {
        int val = cnt[num].back() - cnt[num].front();
        ccnt[val]++;
        bucket[val / sz]++;
    }
    return;
}

void pop(int a) {
    int num = arr[a];
    if (cnt[num].size() >= 2) {
        int val = cnt[num].back() - cnt[num].front();
        ccnt[val]--;
        bucket[val / sz]--;
    }

    if (cnt[num].front() == a) cnt[num].pop_front();
    else cnt[num].pop_back();

    if (cnt[num].size() >= 2) {
        int val = cnt[num].back() - cnt[num].front();
        ccnt[val]++;
        bucket[val / sz]++;
    }

    return;
}

int find_ans() {
    int ret = 0;
    int idx = N / sz + 5;
    for (int i = idx; i >= 0; i--) {
        if (bucket[i] > 0) {
            int pos = (i + 1) * sz + 5;
            for (int j = pos;; j--) {
                if (ccnt[j] > 0) {
                    ret = j;
                    break;
                }
            }
            break;
        }
    }

    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {i, {l, r}};
    }

    while (B * B <= Q) B++;
    B--;

    sz = sqrt(N) * 2;

    sort(q, q + Q, [&](pair<int, pii> a, pair<int, pii> b) {
        if (a.second.first / B == b.second.first / B) return a.second.second < b.second.second;
        return a.second.first / B < b.second.first / B;
    });

    int l = q[0].second.first, r = q[0].second.second, id = q[0].first;
    for (int i = l; i <= r; i++) push(i);
    ans[id] = find_ans();

    for (int i = 1; i < Q; i++) {
        int nl = q[i].second.first, nr = q[i].second.second;
        id = q[i].first;

        while (l > nl) push(--l);
        while (r < nr) push(++r);
        while (l < nl) pop(l++);
        while (r > nr) pop(r--);

        ans[id] = find_ans();
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