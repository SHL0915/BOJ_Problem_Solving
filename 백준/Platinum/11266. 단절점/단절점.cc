#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int V, E, cnt;
vector<int> graph[10005];
int id[10005], cut[10005];

int DFS(int node, int root) {
    id[node] = ++cnt;
    int ret = cnt;
    int child = 0;
    
    for (int next: graph[node]) {
        if (id[next]) ret = min(ret, id[next]);
        else {
            child++;
            int prev = DFS(next, 0);
            if (!root && prev >= id[node]) cut[node] = 1;
            
            ret = min(ret, prev);
        }
    }
    
    if (root && child >= 2) cut[node] = 1;
    
    return ret;
}


void solve() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= V; i++) {
        if (!id[i]) DFS(i, 1);
    }
    
    vector<int> ans;
    for (int i = 1; i <= V; i++) if (cut[i]) ans.push_back(i);
    
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << " ";
    
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