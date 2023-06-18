#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K;
vector<pair<int, pii>> graph[10005];
int table[105][10005];

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({b, {c, d}});
    }

    memset(table, INF, sizeof(table));

    table[1][0] = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            if (table[j][i] == INF) continue;
            for (int k = 0; k < graph[j].size(); k++) {
                int next = graph[j][k].first;
                int cost = graph[j][k].second.first;
                int dist = graph[j][k].second.second;
                if (i + cost > M) continue;
                table[next][i + cost] = min(table[next][i + cost], dist + table[j][i]);
            }
        }
    }


    int ans = INF;
    for (int i = 0; i <= M; i++) ans = min(ans, table[N][i]);
    if (ans == INF) cout << "Poor KCM";
    else cout << ans;

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