#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int arr[1005][1005];
int dist[1005][1005];
queue<pii> q;

void BFS() {
    pii now = q.front();
    q.pop();
    int x = now.first;
    int y = now.second;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (arr[ny][nx] == 0) continue;
        if (dist[ny][nx] != -1) continue;
        dist[ny][nx] = dist[y][x] + 1;
        q.push({nx, ny});
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }

    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 2) {
                dist[i][j] = 0;
                q.push({j, i});
            }
        }
    }

    while (q.size()) BFS();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1) {
                if (arr[i][j] == 0) cout << 0 << " ";
                else cout << -1 << " ";
            } else cout << dist[i][j] << " ";
        }
        cout << '\n';
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