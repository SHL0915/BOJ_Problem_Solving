#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
pii S, E;
int arr[105][105];
int dist[105][105][3];

void Dijkstra(pii start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, pair<pii, int>>, vector<pair<int, pair<pii, int>>>, greater<>> pq;

    dist[start.second][start.first][1] = 0;
    pq.push({0, {start, 1}});

    while (pq.size()) {
        pair<int, pair<pii, int>> t = pq.top();
        pq.pop();
        int val = t.first;
        int x = t.second.first.first, y = t.second.first.second;
        int dir = t.second.second;

        if (dist[y][x][dir] < val) continue;

        if (dir == 0) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
                if (arr[ny][nx] == -1) continue;
                int nval = val + arr[ny][nx], ndir = (dir + 1) % 3;
                if (dist[ny][nx][ndir] > nval) {
                    dist[ny][nx][ndir] = nval;
                    pq.push({nval, {{nx, ny}, ndir}});
                }
            }
        } else if (dir == 1) {
            for (int i = 2; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
                if (arr[ny][nx] == -1) continue;
                int nval = val + arr[ny][nx], ndir = (dir + 1) % 3;
                if (dist[ny][nx][ndir] > nval) {
                    dist[ny][nx][ndir] = nval;
                    pq.push({nval, {{nx, ny}, ndir}});
                }
            }
        } else {
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
                if (arr[ny][nx] == -1) continue;
                int nval = val + arr[ny][nx], ndir = (dir + 1) % 3;
                if (dist[ny][nx][ndir] > nval) {
                    dist[ny][nx][ndir] = nval;
                    pq.push({nval, {{nx, ny}, ndir}});
                }
            }
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    cin >> S.second >> S.first >> E.second >> E.first;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) cin >> arr[i][j];
    }

    Dijkstra(S);

    int ans = INF;
    for (int i = 0; i < 3; i++) ans = min(ans, dist[E.second][E.first][i]);

    if (ans == INF) cout << -1;
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
    //cin >> t;
    while (t--) solve();
    return 0;
}