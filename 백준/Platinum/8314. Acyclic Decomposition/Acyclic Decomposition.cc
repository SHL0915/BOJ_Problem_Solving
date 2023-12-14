#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
int vst[100005], in_degree[100005];
vector<pii> edge;
vector<int> ans[2], graph[100005];

int TopoSort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) if (!in_degree[i]) q.push(i);
    for (int i = 1; i <= N; i++) {
        if (q.size() == 0) return 0;
        int f = q.front();
        q.pop();
        for (int next: graph[f]) {
            if (--in_degree[next] == 0) q.push(next);
        }
    }
    return 1;
}

void DFS(int node) {
    if (vst[node]) return;
    vst[node] = ++cnt;
    for (int next: graph[node]) DFS(next);
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
        graph[a].push_back(b);
        in_degree[b]++;
    }
    
    if (TopoSort()) {
        cout << 1 << '\n' << M << " ";
        for (int i = 1; i <= M; i++) cout << i << " ";
        return;
    }
    
    for (int i = 1; i <= N; i++) DFS(i);
    
    for (int i = 1; i <= M; i++) {
        int a = edge[i - 1].first, b = edge[i - 1].second;
        ans[(vst[a] > vst[b])].push_back(i);
    }
    
    if (ans[0].size() == 0) {
        cout << 1 << '\n';
        cout << M << " ";
        for (int a: ans[1]) cout << a << " ";
    } else if (ans[1].size() == 0) {
        cout << 1 << '\n';
        cout << M << " ";
        for (int a: ans[0]) cout << a << " ";
    } else {
        cout << 2 << '\n';
        for (int i = 0; i < 2; i++) {
            cout << ans[i].size() << " ";
            for (int a: ans[i]) cout << a << " ";
            cout << '\n';
        }
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