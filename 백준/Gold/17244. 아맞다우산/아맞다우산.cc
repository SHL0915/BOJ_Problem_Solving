#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
pii S, E;
int arr[55][55];
int vst[55][55][(1 << 5)];
vector<pii> pos;
queue<pair<pii, int>> q;

void BFS() {
    auto now = q.front();
    q.pop();
    int x = now.first.second, y = now.first.first, state = now.second;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i], ns = state;
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (arr[ny][nx] == -1) continue;
        if (arr[ny][nx] == 1) {
            int idx = -1;
            for (int j = 0; j < pos.size(); j++) {
                if (nx == pos[j].second && ny == pos[j].first) idx = j;
            }
            ns |= (1 << idx);
        }
        if (vst[ny][nx][ns] != -1) continue;
        vst[ny][nx][ns] = vst[y][x][state] + 1;
        q.push({{ny, nx}, ns});
    }
    
    return;
}

void solve() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '#') arr[i][j] = -1;
            if (s[j] == 'S') S = {i, j};
            if (s[j] == 'E') E = {i, j};
            if (s[j] == 'X') {
                pos.push_back({i, j});
                arr[i][j] = 1;
            }
        }
    }
    
    memset(vst, -1, sizeof(vst));
    q.push({S, 0});
    vst[S.first][S.second][0] = 0;
    while (q.size()) BFS();
    
    cout << vst[E.first][E.second][(1 << pos.size()) - 1];
    
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