#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M, Q;
int arr[505][505];
vector<pii> v[1000005];
int par[1000005], parent[1000005][21], level[1000005];
vector<int> tree[1000005];
int ans[1000005];

inline int convert(int x, int y) {
    return y * M + x;
}

int find(int a) {
    if (par[a] == a) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) swap(a, b);
    par[b] = a;
    return;
}

void DFS(int node, int par, int lv) {
    parent[node][0] = par;
    level[node] = lv;
    for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node, lv + 1);
    }
    return;
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 20; i >= 0; i--) {
            if (level[parent[a][i]] >= level[b]) a = parent[a][i];
        }
    }
    int ret = a;
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
            ret = parent[a][i];
        }
    }
    return ret;
}


void solve() {
    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            v[arr[i][j]].push_back({i, j});
            ans[convert(j, i)] = arr[i][j];
        }
    }
    
    for (int i = 0; i <= 1000000; i++) par[i] = i;
    
    int cnt = N * M;
    
    for (int i = 1; i <= 1000000; i++) {
        set<int> s;
        for (auto &[y, x]: v[i]) {
            int now = convert(x, y);
            s.insert(find(now));
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                if (arr[ny][nx] > i) continue;
                int nxt = find(convert(nx, ny));
                s.insert(nxt);
                merge(find(now), nxt);
            }
        }
        
        for (int a: s) {
            if (find(a) == a) {
                merge(cnt, a);
                ans[cnt] = i;
                cnt++;
            }
        }
        
        for (int a: s) tree[find(a)].push_back(a);
    }
    
    DFS(cnt - 1, cnt - 1, 1);
    
    while (Q--) {
        pii a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        a.first--, a.second--, b.first--, b.second--;
        int lca = LCA(convert(a.second, a.first), convert(b.second, b.first));
        cout << ans[lca] << '\n';
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