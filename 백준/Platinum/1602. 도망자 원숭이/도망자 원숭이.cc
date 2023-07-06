#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, Q;
vector<pii> arr;
int adj[505][505];
int add[505][505];
int dist[505][505];

void solve() {
    cin >> N >> M >> Q;

    memset(adj, INF, sizeof(adj));

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        arr.push_back({a, i});
    }

    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a][b] = min(adj[a][b], d);
        adj[b][a] = min(adj[b][a], d);
        add[a][b] = max(arr[a - 1].first, arr[b - 1].first);
        add[b][a] = max(arr[a - 1].first, arr[b - 1].first);
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) dist[i][j] = adj[i][j];
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int mid = arr[k - 1].second;
                int cost = dist[i][mid] + dist[mid][j];
                int add_cost = max(add[i][mid], add[mid][j]);
                if (cost + add_cost < dist[i][j] + add[i][j]) {
                    dist[i][j] = cost;
                    add[i][j] = add_cost;
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int ans = dist[a][b] + add[a][b];
        if (ans >= INF) cout << -1 << '\n';
        else cout << ans << '\n';
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