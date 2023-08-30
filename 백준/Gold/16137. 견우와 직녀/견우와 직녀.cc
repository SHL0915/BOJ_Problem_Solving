#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int arr[15][15];
int dist[15][15][2];

void Dijkstra(pii start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, pair<pii, int>>, vector<pair<int, pair<pii, int>>>, greater<>> pq;
    dist[start.second][start.first][0] = 0;
    pq.push({0, {start, 0}});

    while (pq.size()) {
        pair<int, pair<pii, int>> t = pq.top();
        pq.pop();

        int val = t.first;
        int x = t.second.first.first, y = t.second.first.second, z = t.second.second;

        if (dist[y][x][z] < val) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nval;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (arr[ny][nx] == 0) {
                if (z == 1) continue;
                else {
                    int nz = 1;
                    nval = M * ((val / M) + 1);
                    if (dist[ny][nx][nz] > nval) {
                        dist[ny][nx][nz] = nval;
                        pq.push({nval, {{nx, ny}, nz}});
                    }
                }
            } else {
                if (arr[ny][nx] == 1) {
                    nval = val + 1;
                    if (dist[ny][nx][z] > nval) {
                        dist[ny][nx][z] = nval;
                        pq.push({nval, {{nx, ny}, z}});
                    }
                } else {
                    if (arr[y][x] != 1) continue;
                    nval = arr[ny][nx] * ((val / arr[ny][nx]) + 1);
                    if (dist[ny][nx][z] > nval) {
                        dist[ny][nx][z] = nval;
                        pq.push({nval, {{nx, ny}, z}});
                    }
                }
            }
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> arr[i][j];
    }

    Dijkstra({0, 0});

    cout << min(dist[N - 1][N - 1][0], dist[N - 1][N - 1][1]);
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