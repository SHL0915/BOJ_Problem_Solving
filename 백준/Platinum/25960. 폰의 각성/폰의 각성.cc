#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f3f3f3f3f;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int ddx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ddy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int N;
char arr[1005][1005];
vector<pair<pii, ll>> graph[1005][1005];
ll dist[1005][1005];

void add_edge(int x, int y, int t) {
    if (t == 0) {
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (arr[ny][nx] == '0' || arr[ny][nx] == 'P') continue;
            graph[y][x].push_back({{ny, nx}, 1});
        }
    } else if (t == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 1;; j++) {
                int nx = x + dx[i] * j;
                int ny = y + dy[i] * j;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (arr[ny][nx] == '0' || arr[ny][nx] == 'P') continue;
                graph[y][x].push_back({{ny, nx}, j});
                break;
            }
        }
    } else if (t == 2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 1;; j++) {
                int nx = x + dx[i] * j;
                int ny = y + dy[i] * j;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (arr[ny][nx] == '0' || arr[ny][nx] == 'P') continue;
                graph[y][x].push_back({{ny, nx}, j});
                break;
            }
        }
    } else if (t == 3) {
        for (int i = 4; i < 8; i++) {
            for (int j = 1;; j++) {
                int nx = x + dx[i] * j;
                int ny = y + dy[i] * j;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (arr[ny][nx] == '0' || arr[ny][nx] == 'P') continue;
                graph[y][x].push_back({{ny, nx}, j});
                break;
            }
        }
    } else {
        for (int i = 0; i < 8; i++) {
            int nx = x + ddx[i];
            int ny = y + ddy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (arr[ny][nx] == '0' || arr[ny][nx] == 'P') continue;
            graph[y][x].push_back({{ny, nx}, 2});
        }
    }
}

void Dijkstra(pii s) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<ll, pii>> pq;
    pq.push({0, s});
    dist[s.first][s.second] = 0;
    while (pq.size()) {
        pair<ll, pii> t = pq.top();
        pq.pop();
        ll x = t.second.second, y = t.second.first, cost = -t.first;
        if (dist[y][x] < cost) continue;
        for (pair<pii, ll> next: graph[y][x]) {
            ll ncost = cost + next.second;
            ll nx = next.first.second, ny = next.first.first;
            if (dist[ny][nx] > ncost) {
                dist[ny][nx] = ncost;
                pq.push({-ncost, {ny, nx}});
            }
        }
    }
    return;
}

void solve() {
    cin >> N;
    pii s, e;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'P') {
                s = {i, j};
                add_edge(j, i, 0);
            } else if (arr[i][j] == 'K') e = {i, j};
            else if (arr[i][j] == 'Q') add_edge(j, i, 1);
            else if (arr[i][j] == 'R') add_edge(j, i, 2);
            else if (arr[i][j] == 'B') add_edge(j, i, 3);
            else if (arr[i][j] == 'N') add_edge(j, i, 4);
        }
    }
    
    Dijkstra(s);
    
    ll ans = dist[e.first][e.second];
    
    if (ans >= 1e15) cout << -1;
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