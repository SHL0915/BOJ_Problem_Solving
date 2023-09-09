#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, Q;
vector<int> tree[200005];
ll arr[200005], sz[200005], level[200005], par[200005][25];

void DFS(int node, int p, int lv) {
    level[node] = lv;
    par[node][0] = p;
    sz[node] = 1;
    arr[node] = N - 1;
    ll sum = 0;
    for (int next: tree[node]) {
        if (next == p) continue;
        DFS(next, node, lv + 1);
        sz[node] += sz[next];
        arr[node] += sum * sz[next];
        sum += sz[next];
    }
    arr[node] += sum * (N - sz[node]);
    return;
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 20; i >= 0; i--) {
            if (level[par[a][i]] >= level[b]) a = par[a][i];
        }
    }
    int ret = a;
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
            ret = par[a][i];
        }
    }
    return ret;
}

void solve() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int root = 1;
    DFS(1, 1, 1);

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= N; j++) par[j][i] = par[par[j][i - 1]][i - 1];
    }

    while (Q--) {
        ll a, b;
        cin >> a >> b;
        if (a == 1) root = b;
        else {
            int lca = LCA(root, b);
            if (root == b) cout << arr[b] << '\n';
            else if (lca == b) {
                int now = root;
                for (int i = 20; i >= 0; i--) {
                    if (level[par[now][i]] > level[b]) now = par[now][i];
                }
                cout << arr[b] - (N - sz[now]) * sz[now] << '\n';
            } else cout << arr[b] - sz[b] * (N - sz[b]) << '\n';
        }
    }

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