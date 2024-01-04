#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0}; // E, N, W, S
int dy[4] = {0, 1, 0, -1};

struct robot {
    pii pos;
    int dir;
};

int A, B, N, M;
robot arr[105];
int grid[105][105];

void solve() {
    cin >> A >> B >> N >> M;
    for (int i = 1; i <= N; i++) {
        int x, y, d;
        char c;
        cin >> x >> y;
        cin >> c;
        if (c == 'E') d = 0;
        else if (c == 'N') d = 1;
        else if (c == 'W') d = 2;
        else d = 3;
        grid[y][x] = i;
        arr[i].pos = {x, y};
        arr[i].dir = d;
    }
    
    for (int i = 0; i < M; i++) {
        int idx, n;
        char c;
        
        cin >> idx >> c >> n;
        int &x = arr[idx].pos.first, &y = arr[idx].pos.second, &dir = arr[idx].dir;
        
        for (int j = 0; j < n; j++) {
            if (c == 'L') dir++, dir %= 4;
            else if (c == 'R') dir = dir + 3, dir %= 4;
            else {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 1 || nx > A || ny < 1 || ny > B) {
                    cout << "Robot " << idx << " crashes into the wall";
                    return;
                } else if (grid[ny][nx] != 0 && grid[ny][nx] != idx) {
                    cout << "Robot " << idx << " crashes into robot " << grid[ny][nx];
                    return;
                } else {
                    grid[ny][nx] = idx;
                    grid[y][x] = 0;
                    x = nx;
                    y = ny;
                }
            }
        }
        
    }
    
    cout << "OK";
    
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