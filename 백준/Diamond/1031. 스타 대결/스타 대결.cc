#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
int cap[105][105], flow[105][105], level[105], mark[105];
vector<int> graph[105];

void add_edge(int u, int v, int e) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    cap[u][v] = e;
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

void solve() {
    cin >> N >> M;
    int S = 0, E = N + M + 1, a_sum = 0, b_sum = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        add_edge(S, i, a);
        a_sum += a;
    }

    for (int i = 1; i <= M; i++) {
        int a;
        cin >> a;
        add_edge(N + i, E, a);
        b_sum += a;
    }

    if (a_sum != b_sum) {
        cout << -1;
        return;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= N + M; j++) add_edge(i, j, 1);
    }

    int res = Dinic(S, E);

    if (res != a_sum) {
        cout << -1;
        return;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= N + M; j++) {
            cap[i][j] = 0;
            if (flow[i][j] == 0) cout << 0;
            else {
                flow[S][i]--;
                flow[i][S]++;
                flow[i][j]--;
                flow[j][i]++;
                flow[j][E]--;
                flow[E][j]++;

                if (Dinic(S, E) == 0) {
                    flow[S][i]++;
                    flow[i][S]--;
                    flow[i][j]++;
                    flow[j][i]++;
                    flow[j][E]++;
                    flow[E][j]--;
                    cout << 1;
                } else cout << 0;
            }
        }
        cout << '\n';
    }

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