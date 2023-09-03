#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct edge {
    int to, cap, rev;
};

int H, W;
int arr[105][105];
int level[10505], mark[10505];
vector<edge> graph[10505];

inline int convert(int x, int y) {
    return y * W + x;
}

bool check(int x, int y, int val) {
    if (x < 0 || x >= W || y < 0 || y >= H) return false;
    return arr[y][x] == val;
}

void add_edge(int u, int v, int c) {
    graph[u].push_back({v, c, (int) graph[v].size()});
    graph[v].push_back({u, 0, (int) graph[u].size() - 1});
    return;
}

int DFS(int s, int e, int f) {
    if (s == e) return f;
    for (int &i = mark[s]; i < graph[s].size(); i++) {
        edge &next = graph[s][i];
        if (next.cap > 0 && level[next.to] == level[s] + 1) {
            int ret = DFS(next.to, e, min(f, next.cap));
            if (ret) {
                next.cap -= ret;
                graph[next.to][next.rev].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}

bool BFS(int s, int e) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (q.size()) {
        int now = q.front();
        q.pop();

        for (auto next: graph[now]) {
            if (level[next.to] == -1 && next.cap > 0) {
                level[next.to] = level[now] + 1;
                q.push(next.to);
            }
        }
    }

    return level[e] != -1;
}

int Dinic(int s, int e) {
    int ret = 0;
    while (BFS(s, e)) {
        memset(mark, 0, sizeof(mark));
        while (1) {
            int res = DFS(s, e, 0x3f3f3f3f);
            if (res) ret += res;
            else break;
        }
    }
    return ret;
}

void solve() {
    cin >> H >> W;
    int flag = 0, tot = 0, S = H * W, E = H * W + 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0 || arr[i][j] == 1) flag = 1;
            if ((i + j) % 2 == 0) add_edge(S, convert(j, i), 4 - arr[i][j]);
            else add_edge(convert(j, i), E, 4 - arr[i][j]);
            tot += 4 - arr[i][j];
        }
    }

    if (flag) {
        cout << "HOMELESS";
        return;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] == 4) continue;
            if ((i + j) % 2) continue;

            if (arr[i][j] == 3) {
                for (int k = 0; k < 4; k++) {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if (check(x, y, 2)) add_edge(convert(j, i), convert(x, y), 1);
                }
            }
            for (int k = 0; k < 4; k++) {
                int x = j + dx[k];
                int y = i + dy[k];
                if (check(x, y, 3)) add_edge(convert(j, i), convert(x, y), 1);
            }
        }
    }

    int res = Dinic(S, E);

    if (res * 2 == tot) cout << "HAPPY";
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