#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int arr[305][305], vst[305][305];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

void BFS() {
    pair<int, pii> now = pq.top();
    pq.pop();
    int x = now.second.second, y = now.second.first, v = now.first;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (vst[ny][nx] != -1) continue;
        if (v >= arr[ny][nx]) {
            vst[ny][nx] = v;
            pq.push({v, {ny, nx}});
        } else {
            vst[ny][nx] = arr[ny][nx];
            pq.push({arr[ny][nx], {ny, nx}});
        }
    }
    return;
}

void solve() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }

    memset(vst, -1, sizeof(vst));

    for (int i = 0; i < N; i++) {
        vst[i][0] = arr[i][0];
        vst[i][M - 1] = arr[i][M - 1];
        pq.push({arr[i][0], {i, 0}});
        pq.push({arr[i][M - 1], {i, M - 1}});
    }

    for (int i = 0; i < M; i++) {
        vst[0][i] = arr[0][i];
        vst[N - 1][i] = arr[N - 1][i];
        pq.push({arr[0][i], {0, i}});
        pq.push({arr[N - 1][i], {N - 1, i}});
    }

    while (pq.size()) BFS();
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += vst[i][j] - arr[i][j];
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