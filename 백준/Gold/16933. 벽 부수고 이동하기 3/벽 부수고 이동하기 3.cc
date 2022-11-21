#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, ans;
int map[1001][1001];
int mark[1001][1001][11][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue <pair<pair<int, int>, pair<int, int>>> q;

void BFS();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) map[i][j] = s[j] - '0';
    }
    mark[0][0][0][0] = 1;
    q.push({ {0,0},{0,0} });
    while (q.size()) BFS();
    ans = -1;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < 2; j++) {
            if (mark[N - 1][M - 1][i][j] == 0) continue;
            if (ans == -1 || ans > mark[N - 1][M - 1][i][j]) {
                ans = mark[N - 1][M - 1][i][j];
            }
        }
    }
    cout << ans;
    return 0;
}

void BFS() {
    pair<pair<int, int>, pair<int, int>> f = q.front();
    q.pop();
    int x = f.first.first;
    int y = f.first.second;
    int k = f.second.first;
    int d = f.second.second;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1) continue;
        if (map[ny][nx] == 0 && mark[ny][nx][k][1 - d] == 0) {
            mark[ny][nx][k][1 - d] = mark[y][x][k][d] + 1;
            q.push({ {nx,ny},{k,1 - d} });
        }
        if (d == 0 && k <= K - 1 && map[ny][nx] == 1 && mark[ny][nx][k + 1][1 - d] == 0) {
            mark[ny][nx][k + 1][1 - d] = mark[y][x][k][d] + 1;
            q.push({ {nx,ny},{k + 1,1 - d} });
        }
    }
    if (mark[y][x][k][1 - d] == 0) {
        mark[y][x][k][1 - d] = mark[y][x][k][d] + 1;
        q.push({ {x,y},{k,1 - d} });
    }      
    return;
}