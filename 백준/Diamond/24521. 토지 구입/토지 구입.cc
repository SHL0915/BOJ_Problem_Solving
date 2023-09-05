#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M, K;
int arr[105][105];
int cost[1005][1005];
int A[105][105], B[105][105];
int cap[1005][1005], flow[1005][1005], level[1005], mark[1005];
int ans[105][105];
vector<int> graph[1005];

void add_edge(int u, int v, int c) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = c;
    return;
}

int DFS(int s, int e, int f) {
    if (s == e) return f;
    for (int &i = mark[s]; i < graph[s].size(); i++) {
        int next = graph[s][i];
        if (level[next] == level[s] + 1 && cap[s][next] - flow[s][next] > 0) {
            int res = DFS(next, e, min(f, cap[s][next] - flow[s][next]));
            if (res) {
                flow[s][next] += res;
                flow[next][s] -= res;
                return res;
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
        for (int next: graph[now]) {
            if (level[next] == -1 && cap[now][next] - flow[now][next] > 0) {
                level[next] = level[now] + 1;
                q.push(next);
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
            int res = DFS(s, e, INF);
            if (res) ret += res;
            else break;
        }
    }
    return ret;
}

void check(int node) {
    if (mark[node]) return;
    mark[node] = 1;
    for (int next: graph[node]) {
        if (cap[node][next] - flow[node][next] > 0) check(next);
    }
    return;
}

void solve() {
    cin >> N >> M >> K;
    int S = N * M, E = N * M + 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }
    
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) cin >> cost[i][j];
    }
    
    auto f = [&](int x, int y) { return y * M + x; };
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            add_edge(S, f(j, i), A[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
            add_edge(f(j, i), E, B[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int x = j + dx[k];
                int y = i + dy[k];
                if (x < 0 || x >= M || y < 0 || y >= N) continue;
                int a = arr[y][x], b = arr[i][j];
                add_edge(f(x, y), f(j, i), cost[a][b]);
                add_edge(f(j, i), f(x, y), cost[a][b]);
            }
        }
    }
    
    Dinic(S, E);
    memset(mark, 0, sizeof(mark));
    check(S);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mark[f(j, i)]) ans[i][j] = 1;
            else ans[i][j] = 0;
        }
    }
    
    set<pii> s;
    
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ans[i][j] == 1) tot += A[i][j];
            else tot += B[i][j];
            for (int k = 0; k < 4; k++) {
                int x = j + dx[k];
                int y = i + dy[k];
                if (x < 0 || x >= M || y < 0 || y >= N) continue;
                if (ans[y][x] != ans[i][j]) continue;
                int aa = f(x, y), bb = f(j, i);
                if (aa > bb) swap(aa, bb);
                pii c = {aa, bb};
                if (s.count(c)) continue;
                s.insert(c);
                int a = arr[y][x], b = arr[i][j];
                tot += cost[a][b];
            }
        }
    }
    
    cout << tot << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ans[i][j] == 1) cout << "L";
            else cout << "R";
        }
        cout << '\n';
    }
    
    return;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}