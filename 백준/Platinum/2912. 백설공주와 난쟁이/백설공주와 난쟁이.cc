#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 10005;

int N, C, M;
int arr[300005], ans[10005];
int cnt[10005];
pair<pii, int> query[10005];

inline void add(int a) {
    cnt[arr[a]]++;
    return;
}

inline void del(int a) {
    cnt[arr[a]]--;
    return;
}

pii find_max() {
    int a = 0, b = 0;
    for (int i = 1; i <= C; i++) {
        if (cnt[i] > a) a = cnt[i], b = i;
    }
    return {a, b};
}

void solve() {
    cin >> N >> C;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        query[i] = {{a, b}, i};
    }

    int B = 0;
    while (B * B <= N) B++;
    B--;

    sort(query, query + M, [&](pair<pii, int> a, pair<pii, int> b) {
        if (a.first.first / B == b.first.first / B) return a.first.second < b.first.second;
        return a.first.first / B < b.first.first / B;
    });

    int l = query[0].first.first, r = query[0].first.second;
    for (int i = l; i <= r; i++) add(i);

    pii qq = find_max();
    if (qq.first * 2 > r - l + 1) ans[query[0].second] = qq.second;
    else ans[query[0].second] = -1;

    for (int i = 1; i < M; i++) {
        int nl = query[i].first.first, nr = query[i].first.second, idx = query[i].second;
        while (l > nl) add(--l);
        while (l < nl) del(l++);
        while (r > nr) del(r--);
        while (r < nr) add(++r);
        pii qq = find_max();
        if (qq.first * 2 > r - l + 1) ans[idx] = qq.second;
        else ans[idx] = -1;
    }

    for (int i = 0; i < M; i++) {
        if (ans[i] == -1) cout << "no\n";
        else cout << "yes " << ans[i] << '\n';
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