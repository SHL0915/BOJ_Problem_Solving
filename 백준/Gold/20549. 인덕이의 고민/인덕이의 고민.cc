#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, A, B, C, M;
pii S;
pii pos[4];
int dist[51][51][16];

void Dijkstra(pii start);

void solve() {
    cin >> N >> A >> B >> C;
    cin >> S.first >> S.second;
    cin >> M;
    for (int i = 0; i < M; i++) cin >> pos[i].first >> pos[i].second;
    Dijkstra(S);
    int ans = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = min(ans, dist[i][j][(1 << M) - 1]);
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

void Dijkstra(pii start) {
    memset(dist, INF, sizeof(dist));
    priority_queue <pair<int, pair<pii,int>>, vector <pair<int, pair<pii, int>>>, greater<>> pq;
    int state = 0;
    int x = start.first, y = start.second;
    for (int i = 0; i < M; i++) {
        if (x == pos[i].first && y == pos[i].second) state |= (1 << i);
    }
    dist[x][y][state] = 0;
    pq.push({ 0,{{x,y}, state} });
    while (pq.size()) {
        x = pq.top().second.first.first;
        y = pq.top().second.first.second;
        state = pq.top().second.second;
        int val = pq.top().first;
        pq.pop();
        if (dist[x][y][state] < val) continue;

        int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
        int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + A) {
                dist[nx][ny][ns] = val + A;
                pq.push({ val + A, {{nx,ny},ns} });
            }            
        }

        for (int i = 1; i < N; i++) {
            int nx = x + i;
            int ny = y + i;
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + B) {
                dist[nx][ny][ns] = val + B;
                pq.push({ val + B, {{nx,ny},ns} });
            }
        }

        for (int i = 1; i < N; i++) {
            int nx = x + i;
            int ny = y - i;
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + B) {
                dist[nx][ny][ns] = val + B;
                pq.push({ val + B, {{nx,ny},ns} });
            }
        }

        for (int i = 1; i < N; i++) {
            int nx = x - i;
            int ny = y + i;
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + B) {
                dist[nx][ny][ns] = val + B;
                pq.push({ val + B, {{nx,ny},ns} });
            }
        }

        for (int i = 1; i < N; i++) {
            int nx = x - i;
            int ny = y - i;
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + B) {
                dist[nx][ny][ns] = val + B;
                pq.push({ val + B, {{nx,ny},ns} });
            }
        }

        for (int i = 0; i < N; i++) {
            int nx = i;
            int ny = y;
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + C) {
                dist[nx][ny][ns] = val + C;
                pq.push({ val + C, {{nx,ny},ns} });
            }
        }

        for (int i = 0; i < N; i++) {
            int nx = x;
            int ny = i;
            int ns = state;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int i = 0; i < M; i++) {
                if (nx == pos[i].first && ny == pos[i].second) ns |= (1 << i);
            }

            if (dist[nx][ny][ns] > val + C) {
                dist[nx][ny][ns] = val + C;
                pq.push({ val + C, {{nx,ny},ns} });
            }
        }
    }
}