#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int arr[605][605];
int vst[605][605];
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
        if (vst[ny][nx] == 1) continue;
        if (arr[ny][nx] == 1) continue;
        vst[ny][nx] = 1;
        q.push({nx, ny});
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++) {
            if (input[j] == 'X') arr[i][j] = 1;
            else {
                if (input[j] == 'P') arr[i][j] = 2;
                if (input[j] == 'I') {
                    vst[i][j] = 1;
                    q.push({j, i});
                }
            }
        }
    }

    while (q.size()) BFS();

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vst[i][j] == 1 && arr[i][j] == 2) cnt++;
        }
    }

    if (cnt == 0) cout << "TT";
    else cout << cnt;
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