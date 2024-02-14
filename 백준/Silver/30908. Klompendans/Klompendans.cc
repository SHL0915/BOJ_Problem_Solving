#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

int N, a, b, c, d;
int vst[505][505][2];
queue<pair<pii, int>> q;

void BFS() {
    pii now = q.front().first;
    int t = q.front().second;
    q.pop();
    int x = now.second, y = now.first;
    int nx, ny;

    if (t == 0) {
        for (int i = 0; i < 4; i++) {
            nx = x + a * dx[i], ny = y + b * dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vst[ny][nx][1]) continue;
            vst[ny][nx][1] = 1;
            q.push({{ny, nx}, 1});
        }

        for (int i = 0; i < 4; i++) {
            nx = x + b * dx[i], ny = y + a * dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vst[ny][nx][1]) continue;
            vst[ny][nx][1] = 1;
            q.push({{ny, nx}, 1});
        }
    } else {
        for (int i = 0; i < 4; i++) {
            nx = x + c * dx[i], ny = y + d * dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vst[ny][nx][0]) continue;
            vst[ny][nx][0] = 1;
            q.push({{ny, nx}, 0});
        }

        for (int i = 0; i < 4; i++) {
            nx = x + d * dx[i], ny = y + c * dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vst[ny][nx][0]) continue;
            vst[ny][nx][0] = 1;
            q.push({{ny, nx}, 0});
        }
    }

    return;
}

void solve() {
    cin >> N >> a >> b >> c >> d;

    vst[0][0][0] = 1, vst[0][0][1] = 1;
    q.push({{0, 0}, 0});
    q.push({{0, 0}, 1});
    while (q.size()) BFS();

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vst[i][j][0] || vst[i][j][1]) ans++;
        }
    }

    cout << ans;

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