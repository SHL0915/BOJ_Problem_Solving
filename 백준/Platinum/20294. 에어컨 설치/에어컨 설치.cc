#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct dot {
    int x, y, z;
};

int N;
dot arr[1505];
vector<int> graph[1505], bipartite[1505];
vector<pii> edge;
int mark[1505], A[1505], B[1505], color[1505];

inline ll dist(dot a, dot b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    ll dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}

void make_bipartite(int node) {
    for (int next: graph[node]) {
        if (mark[next] != -1) continue;
        mark[next] = mark[node] ^ 1;
        make_bipartite(next);
    }
    return;
}

int DFS(int node) {
    mark[node] = 1;
    for (int next: bipartite[node]) {
        if (B[next] == -1 || mark[B[next]] == 0 && DFS(B[next])) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist(arr[i], arr[j]) == 1) {
                graph[i].push_back(j);
                edge.push_back({i, j});
            }
        }
    }
    
    memset(mark, -1, sizeof(mark));
    for (int i = 1; i <= N; i++) {
        if (mark[i] == -1) {
            mark[i] = 0;
            make_bipartite(i);
        }
    }
    
    for (int i = 1; i <= N; i++) color[i] = mark[i];
    
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].first, b = edge[i].second;
        if (mark[a] == 1) swap(a, b);
        bipartite[a].push_back(b);
    }
    
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (color[i] == 1) continue;
        if (A[i] == -1) {
            memset(mark, 0, sizeof(mark));
            ans += DFS(i);
            if (bipartite[i].size() == 0) ans++;
        }
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