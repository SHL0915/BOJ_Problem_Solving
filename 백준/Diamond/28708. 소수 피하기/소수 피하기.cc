#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int sieve[3000005];
int arr[205];
vector<int> graph[205];
int flow[205][205], cap[205][205], level[205], mark[205];

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
            int ret = DFS(next, e, min(f, cap[s][next] - flow[s][next]));
            if (ret) {
                flow[s][next] += ret;
                flow[next][s] -= ret;
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
    cin >> N;
    int S = 0, E = N + 1;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == 1) cnt++;
        if (arr[i] % 2 == 0) add_edge(S, i, 1);
        else add_edge(i, E, 1);
    }
    
    if (cnt > 1) {
        for (int i = 1; i <= N; i++) {
            if (arr[i] == 1) add_edge(S, i, INF);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            int Ei = arr[i];
            if (Ei % 2) Ei++;
            int Oj = arr[j];
            if (Oj % 2 == 0) Oj++;
            
            if (sieve[Ei + Oj] == 0) add_edge(i, j, INF);
        }
    }
    
    int ans = Dinic(S, E);
    BFS(S, E);
    
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (level[i] == -1 && arr[i] % 2 == 0) v.push_back(i);
        else if (level[i] != -1 && arr[i] % 2) v.push_back(i);
    }
    
    cout << ans << '\n';
    for (int a: v) cout << a << " ";
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (ll i = 2; i < 3000005; i++) {
        if (sieve[i] == 0) {
            for (ll j = i * i; j < 3000005; j += i) sieve[j] = 1;
        }
    }
    //cin >> t;
    while (t--) solve();
    return 0;
}