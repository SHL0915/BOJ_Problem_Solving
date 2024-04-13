#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100005;

int N, Q;
vector<int> graph[SZ];
int parent[SZ][21], level[SZ];

void DFS(int node, int par, int lv) {
    parent[node][0] = par;
    level[node] = lv;
    for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
    for (int next: graph[node]) {
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

int find(int a, int k) {
    int ret = a;
    if (k == 0) return a;
    int kk = level[a] - k;
    for (int i = 20; i >= 0; i--) {
        if (level[parent[a][i]] > kk) a = parent[a][i];
        ret = parent[a][i];
    }
    return ret;
}

int dist(int a, int b) {
    int lca = LCA(a, b);
    return abs(level[a] - level[lca]) + abs(level[b] - level[lca]);
}

int f(int a, int b, int c) {
    int m = LCA(a, b);
    int da = dist(a, m), db = dist(b, m);
    if (da > db) swap(a, b), swap(da, db);
    if ((db - da) % 2) return -1;
    m = find(b, db - (db - da) / 2);
    int k = (da + db) / 2;


    int dm = dist(m, c);
    if (dm < k) return -1;
    if ((dm - k) % 2) return -1;
    int lca = LCA(m, c);

    int dl = dist(lca, m);
    int ret = -1;
    if (k + 2 * dl <= dm) {
        k += dl;
        dm -= dl;
        ret = find(c, dm - dl - (dm - (k + 2 * dl)) / 2);
    } else ret = find(m, (dm - k) / 2);

    if (dist(a, ret) == dist(b, ret) && dist(b, ret) == dist(c, ret)) return ret;
    else return -1;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1, 1, 1);

    cin >> Q;
    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = -1;
        ans = max(ans, f(a, b, c));
        ans = max(ans, f(a, c, b));
        ans = max(ans, f(b, c, a));

        cout << ans << '\n';
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