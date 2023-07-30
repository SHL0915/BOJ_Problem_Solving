#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3;

int N, M;
int arr[5005];
vector<pair<pii, int>> edge;
vector<int> graph[55005];
map<int, int> flow[55005], cap[55005];
int level[55005], mark[55005], vst[55005];

void add_edge(int s, int e, int c) {
    graph[s].push_back(e);
    graph[e].push_back(s);
    
    cap[s][e] += c;
    
    return;
}

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
    queue<int> q;
    memset(level, -1, sizeof(level));
    level[S] = 0;
    q.push(S);
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

void chk(int S) {
    if (vst[S]) return;
    vst[S] = 1;
    for (int next: graph[S]) {
        if (cap[S][next] - flow[S][next] > 0) chk(next);
    }
    
    return;
}


void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        add_edge(M + i, M + N + 1, arr[i]);
    }
    
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{a, b}, c});
        add_edge(0, i, c);
        add_edge(i, M + a, INF);
        add_edge(i, M + b, INF);
    }
    
    Dinic(0, M + N + 1);
    chk(0);
    
    ll ans = 0;
    
    for (int i = 1; i <= N; i++) if (vst[i + M]) ans -= arr[i];
    for (int i = 1; i <= M; i++) if (vst[i]) ans += edge[i - 1].second;
    
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