#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K, M, ans;
vector<pii> edge;
int mark[55];

void BackTracking(int idx, int cnt);

void solve() {
    cin >> N >> K >> M;

    edge.clear();
    memset(mark, -1, sizeof(mark));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
    }

    ans = INF;
    BackTracking(0, 0);

    if (ans > K) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

void BackTracking(int idx, int cnt) {
    if (cnt > K) return;
    if (idx == M) {
        ans = min(ans, cnt);
        return;
    }

    int a = edge[idx].first, b = edge[idx].second;
    if (mark[a] == -1 && mark[b] == -1) {
        mark[a] = 1;
        BackTracking(idx + 1, cnt + 1);
        mark[a] = -1;

        mark[b] = 1;
        BackTracking(idx + 1, cnt + 1);
        mark[b] = -1;
    }
    else BackTracking(idx + 1, cnt);
}