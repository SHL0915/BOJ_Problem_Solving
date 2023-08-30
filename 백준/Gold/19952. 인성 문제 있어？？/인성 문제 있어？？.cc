#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int H, W, O, F;
pii S, E;
int arr[105][105];
int mark[105][105];
queue<pii> q;

void BFS() {
    pii f = q.front();
    q.pop();
    int x = f.first, y = f.second;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > W || ny < 1 || ny > H) continue;
        if (arr[ny][nx] - arr[y][x] > mark[y][x]) continue;
        if (mark[ny][nx] != -1) continue;
        mark[ny][nx] = mark[y][x] - 1;
        q.push({nx, ny});
    }

    return;
}

void solve() {
    cin >> W >> H >> O >> F;
    cin >> S.first >> S.second >> E.first >> E.second;

    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < O; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        arr[y][x] = l;
    }

    memset(mark, -1, sizeof(mark));
    mark[S.second][S.first] = F;
    q.push(S);

    while (q.size()) BFS();

    if (mark[E.second][E.first] < 0) cout << "인성 문제있어??";
    else cout << "잘했어!!";

    cout << endl;

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}