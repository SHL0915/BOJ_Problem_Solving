#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int V, E, cnt;
vector<int> graph[100005];
int id[100005];
vector<pii> cut;

int DFS(int node, int par) {
    id[node] = ++cnt;
    int ret = cnt;
    
    for (int next: graph[node]) {
        if (next == par) continue;
        if (id[next]) ret = min(ret, id[next]);
        else {
            int prev = DFS(next, node);
            if (prev > id[node]) cut.push_back({min(node, next), max(node, next)});
            
            ret = min(ret, prev);
        }
    }
    
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
        if (!id[i]) DFS(i, 0);
    }
    
    sort(cut.begin(), cut.end());
    
    cout << cut.size() << '\n';
    for (pii a: cut) cout << a.first << " " << a.second << '\n';
    
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