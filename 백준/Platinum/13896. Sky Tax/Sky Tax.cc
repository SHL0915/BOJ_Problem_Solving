#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 100005;

int N, Q, R;
vector<int> graph[SZ];
int table[SZ], level[SZ], parent[SZ][21];

void init() {
    for (int i = 1; i <= N; i++) {
        graph[i].clear();
        table[i] = 0;
        level[i] = 0;
        for (int j = 0; j < 21; j++) parent[i][j] = 0;
    }

    return;
}

void DFS(int node, int par, int lv);

int LCA(int a, int b);

void solve() {
    cin >> N >> Q >> R;
    init();

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1, 1, 1);

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0) R = b;
        else {
            if (R == b) {
                cout << N << '\n';
                continue;
            }

            int lca = LCA(R, b);
            if (lca == b) {
                int temp = R;
                int lv = level[b] + 1;
                for (int i = 20; i >= 0; i--) {
                    if (level[parent[temp][i]] >= lv) temp = parent[temp][i];
                }
                cout << N - table[temp] << '\n';
            } else cout << table[b] << '\n';
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
    int t = 1, tc = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << tc << ":\n";
        solve();
        tc++;
    }
    return 0;
}

void DFS(int node, int par, int lv) {
    level[node] = lv;
    parent[node][0] = par;
    for (int i = 1; i < 21; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];

    table[node] = 1;

    for (int next: graph[node]) {
        if (next == par) continue;
        DFS(next, node, lv + 1);
        table[node] += table[next];
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