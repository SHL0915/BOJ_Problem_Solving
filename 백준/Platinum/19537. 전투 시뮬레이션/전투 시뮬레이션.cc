#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct unit {
    int m, t, a, b;
};

int N, H, W, M;
int arr[505][505];
int pos[505][505];
int A[505];
pii dist[505][505];
vector<unit> v;

int chk(int x, int y, int idx) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
        if (pos[ny][nx] == -1) continue;
        if (v[pos[ny][nx]].t == v[idx].t) continue;
        return 1;
    }

    return 0;
}

void Dijkstra(pii start, int id, int idx) {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    pq.push({0, start});
    dist[start.second][start.first] = {0, id};

    while (pq.size()) {
        pair<int, pii> t = pq.top();
        pq.pop();
        int x = t.second.first;
        int y = t.second.second;
        int val = t.first;

        if (dist[y][x].second == id && dist[y][x].first < val) continue;
        if ((x != start.first || y != start.second) && chk(x, y, idx)) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (arr[ny][nx] == -1) continue;
            if (pos[ny][nx] != -1 && v[pos[ny][nx]].t != v[idx].t) continue;
            int nval = val + arr[ny][nx];
            if (nval > v[idx].m) continue;

            if (dist[ny][nx].second != id || (dist[ny][nx].second == id && dist[ny][nx].first > nval)) {
                dist[ny][nx] = {nval, id};
                pq.push({nval, {nx, ny}});
            }
        }
    }

    return;
}

void f(int u, int a, int b, int id) {
    if (arr[a][b] == -1) return;
    if (pos[a][b] != -1) return;

    Dijkstra({v[u].b, v[u].a}, id, u);

    if (dist[a][b].second != id || (dist[a][b].second == id && dist[a][b].first > v[u].m)) return;
    else {
        pos[v[u].a][v[u].b] = -1;
        pos[a][b] = u;
        v[u].a = a;
        v[u].b = b;
    }

    return;
}

void solve() {
    cin >> N >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> arr[i][j];
    }

    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) arr[i][j] = A[arr[i][j]];
    }

    memset(pos, -1, sizeof(pos));

    cin >> M;
    for (int i = 0; i < M; i++) {
        int m, t, a, b;
        cin >> m >> t >> a >> b;
        v.push_back({m, t, a, b});
        pos[a][b] = i;
    }

    int K;
    cin >> K;
    for (int i = 1; i <= K; i++) {
        int u, a, b;
        cin >> u >> a >> b;
        f(u - 1, a, b, i);
    }

    for (int i = 0; i < M; i++) cout << v[i].a << " " << v[i].b << '\n';

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