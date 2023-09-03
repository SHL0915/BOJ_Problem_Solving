#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int H, W;
int arr[505][505];
int A[50505], B[50505], mark[50505];
vector<int> graph[50505];

bool check(int x, int y, int val) {
    if (x < 0 || x >= W || y < 0 || y >= H) return false;
    return arr[y][x] == val;
}

int DFS(int node, int org) {
    mark[node] = org;
    for (int next: graph[node]) {
        if (B[next] == -1 || mark[B[next]] != org && DFS(B[next], org)) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> H >> W;
    int flag = 0, tot = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] < 2) flag = 1;
            tot += 4 - arr[i][j];
        }
    }

    if (flag) {
        cout << "HOMELESS";
        return;
    }

    auto to = [&](int x, int y) {
        return (y * W + x) * 2;
    };

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] == 4) continue;
            if ((i + j) % 2) continue;

            if (arr[i][j] == 3) {
                for (int k = 0; k < 4; k++) {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if (check(x, y, 2)) {
                        graph[to(j, i)].push_back(to(x, y));
                        graph[to(j, i)].push_back(to(x, y) + 1);
                    }
                    if (check(x, y, 3)) graph[to(j, i)].push_back(to(x, y));
                }
            }
            if (arr[i][j] == 2) {
                for (int k = 0; k < 4; k++) {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if (check(x, y, 3)) {
                        graph[to(j, i)].push_back(to(x, y));
                        graph[to(j, i) + 1].push_back(to(x, y));
                    }
                }
            }
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    memset(mark, -1, sizeof(mark));

    int ans = 0;
    for (int i = 0; i < H * W * 2 + 5; i++) {
        if (A[i] == -1) ans += DFS(i, i);
    }

    if (ans * 2 == tot) cout << "HAPPY";
    else cout << "HOMELESS";

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