#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
pii arr[55];
vector<int> graph[105];
int cap[105][105], flow[105][105], level[105], mark[105];

int DFS(int S, int E, int F) {
    if (S == E) return F;

    for (int &i = mark[S]; i < graph[S].size(); i++) {
        int next = graph[S][i];
        if (level[next] == level[S] + 1 && cap[S][next] - flow[S][next] > 0) {
            int ret = DFS(next, E, min(F, cap[S][next] - flow[S][next]));
            if (ret) {
                flow[S][next] += ret;
                flow[next][S] -= ret;
                return ret;
            }
        }
    }

    return 0;
}

int BFS(int S, int E) {
    memset(level, -1, sizeof(level));
    queue<int> q;

    q.push(S);
    level[S] = 0;

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

    return level[E] != -1;
}

int Dinic(int S, int E) {
    int ret = 0;
    while (BFS(S, E)) {
        memset(mark, 0, sizeof(mark));
        while (1) {
            int res = DFS(S, E, INF);
            if (res) ret += res;
            else break;
        }
    }
    return ret;
}

void add_edge(int s, int e, int c) {
    graph[s].push_back(e);
    graph[e].push_back(s);
    cap[s][e] = c;
    return;
}

void init() {
    for (int i = 0; i < 2 * N + 1; i++) graph[i].clear();
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0, ccnt = 0;
        init();
        for (int j = 1; j <= N; j++) {
            if (j == i) continue;
            if (arr[j].first == i || arr[j].second == i) cnt++;
            else {
                add_edge(j, arr[j].first + N, 1);
                add_edge(arr[j].first + N, j, 1);

                add_edge(j, arr[j].second + N, 1);
                add_edge(arr[j].second + N, j, 1);
                ccnt++;
            }
        }

        for (int j = 1; j <= N; j++) {
            add_edge(0, j, 1);

            if (j == arr[i].first || j == arr[i].second) add_edge(N + j, 2 * N + 1, cnt - 2);
            else add_edge(N + j, 2 * N + 1, cnt - 1);
        }

        int res = Dinic(0, 2 * N + 1);

        if (cnt < 2 || res < ccnt) ans++;
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