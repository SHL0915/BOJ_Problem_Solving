#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int H, W;
int arr[205][205], vst[205][205];
queue<pii> q;

void BFS() {
    pii now = q.front();
    q.pop();
    int x = now.second, y = now.first;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if (arr[ny][nx] == 1 || vst[ny][nx] != -1) continue;
        vst[ny][nx] = vst[y][x] + 1;
        q.push({ny, nx});
    }

    return;
}

void solve() {
    cin >> H >> W;
    pii pos;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == '#') arr[i][j] = 1;
            else if (s[j] == '%') pos = {i, j};
            else if (s[j] == '@') arr[i][j] = 2;
            else if (s[j] == '$') arr[i][j] = 3;
        }
    }

    memset(vst, -1, sizeof(vst));
    vst[pos.first][pos.second] = 0;
    q.push(pos);

    while (q.size()) BFS();

    int a = 1e9, b = 1e9;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] == 2) a = min(a, vst[i][j]);
            if (arr[i][j] == 3) b = min(b, vst[i][j]);
        }
    }

    if (a >= b) cout << "No";
    else cout << "Yes";

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