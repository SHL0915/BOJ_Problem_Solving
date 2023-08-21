#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N, M;
pair<pii, pair<int, pii>> q[300005];
pair<int, pii> arr[300005];
int ans[300005];
set<int> cup[300005];

void solve() {
    cin >> K >> N >> M;
    for (int i = 1; i <= N - 1; i++) cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
    for (int i = 1; i <= M; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cup[a].insert(i);
        q[i] = {{b, i},
                {c, {d, e}}};
    }
    sort(q + 1, q + 1 + M);

    int qidx = 1;
    for (int i = 1; i <= N - 1; i++) {
        while (q[qidx].first.first == i) {
            int t = q[qidx].second.first, id = q[qidx].first.second;
            int a = q[qidx].second.second.first, b = q[qidx].second.second.second;
            if (t == 1) {
                if (cup[a].count(id)) {
                    cup[a].erase(id);
                    cup[b].insert(id);
                } else if (cup[b].count(id)) {
                    cup[a].insert(id);
                    cup[b].erase(id);
                }
            } else {
                if (cup[a].count(id)) {
                    cup[a].erase(id);
                    cup[b].insert(id);
                }
            }
            qidx++;
        }

        int t = arr[i].first, a = arr[i].second.first, b = arr[i].second.second;
        if (t == 1) swap(cup[a], cup[b]);
        else {
            if (cup[a].size() > cup[b].size()) {
                for (int e: cup[b]) cup[a].insert(e);
                cup[b].clear();
                swap(cup[a], cup[b]);
            } else {
                for (int e: cup[a]) cup[b].insert(e);
                cup[a].clear();
            }
        }
    }

    while (q[qidx].first.first == N) {
        int t = q[qidx].second.first, id = q[qidx].first.second;
        int a = q[qidx].second.second.first, b = q[qidx].second.second.second;
        if (t == 1) {
            if (cup[a].count(id)) {
                cup[a].erase(id);
                cup[b].insert(id);
            } else if (cup[b].count(id)) {
                cup[a].insert(id);
                cup[b].erase(id);
            }
        } else {
            if (cup[a].count(id)) {
                cup[a].erase(id);
                cup[b].insert(id);
            }
        }
        qidx++;
    }

    for (int i = 1; i <= K; i++) {
        for (int e: cup[i]) ans[e] = i;
    }

    for (int i = 1; i <= M; i++) cout << ans[i] << '\n';

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