#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct qnode {
    int now, org;
};

int N, ans, sz;
int arr[100005];
vector<int> idx[100005];
vector<int> tree[100005];
int parent[100005][20], level[100005];
int mark[100005][2];
queue<qnode> q;

void DFS(int node, int p, int lv) {
    parent[node][0] = p;
    level[node] = lv;
    for (int i = 1; i <= 18; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];
    for (int next: tree[node]) {
        if (next == p) continue;
        DFS(next, node, lv + 1);
    }
    return;
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 18; i >= 0; i--) {
            if (level[parent[a][i]] >= level[b]) a = parent[a][i];
        }
    }

    int ret = a;
    if (a != b) {
        for (int i = 18; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) a = parent[a][i], b = parent[b][i];
            ret = parent[a][i];
        }
    }

    return ret;
}

void BFS() {
    qnode f = q.front();
    q.pop();

    if (mark[f.now][0] > ans / 2) return;

    for (int next: tree[f.now]) {
        if (mark[next][0] == -1) {
            mark[next][0] = mark[f.now][0] + 1;
            mark[next][1] = mark[f.now][1];
            q.push({next, f.org});
        } else {
            if (mark[next][1] == f.org) continue;
            else {
                ans = min(ans, mark[next][0] + mark[f.now][0] + 1);
                return;
            }
        }
    }

    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        idx[arr[i]].push_back(i);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    ans = N;

    DFS(1, 1, 1);
    for (int i = 1; i <= N; i++) {
        if (idx[i].size() <= 100) {
            for (int j = 0; j < idx[i].size(); j++) {
                for (int k = j + 1; k < idx[i].size(); k++) {
                    int a = idx[i][j], b = idx[i][k];
                    int lca = LCA(a, b);
                    ans = min(ans, level[a] + level[b] - 2 * level[lca]);
                }
            }
        } else {
            memset(mark, -1, sizeof(mark));
            for (int a: idx[i]) {
                q.push({a, a});
                mark[a][0] = 0;
                mark[a][1] = a;
            }
            while (q.size()) BFS();
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