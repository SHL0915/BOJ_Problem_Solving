#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, Q, root = 1;
vector<int> graph[200005];
ll arr[200005], level[200005], sz[200005];
int parent[200005][25];

void DFS(int node, int par, int lv) {
    level[node] = lv;
    sz[node] = 1;
    parent[node][0] = par;

    for (int i = 1; i <= 20; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];

    ll sum = 0;
    for (int next: graph[node]) {
        if (next == par) continue;
        DFS(next, node, lv + 1);
        sz[node] += sz[next];
        arr[node] += sz[next];
        arr[node] += sum * sz[next];
        sum += sz[next];
    }

    arr[node] += N - sz[node];
    arr[node] += sum * (N - sz[node]);
    return;
}

int LCA(int A, int B) {
    if (level[A] < level[B]) swap(A, B);
    if (level[A] != level[B]) {
        for (int i = 20; i >= 0; i--) {
            if (level[parent[A][i]] >= level[B]) A = parent[A][i];
        }
    }
    int ret = A;
    if (A != B) {
        for (int i = 20; i >= 0; i--) {
            if (parent[A][i] != parent[B][i]) {
                A = parent[A][i];
                B = parent[B][i];
            }
            ret = parent[A][i];
        }
    }
    return ret;
}

void solve() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1, 1, 1);

    while (Q--) {
        ll a, b;
        cin >> a >> b;
        if (a == 1) root = b;
        else {
            int lca = LCA(root, b);
            if (root == b) cout << arr[b] << '\n';
            else if (lca != b) cout << arr[b] - sz[b] * (N - sz[b]) << '\n';
            else {
                int now = root;
                for (int i = 20; i >= 0; i--) {
                    if (level[parent[now][i]] > level[b]) now = parent[now][i];
                }
                cout << arr[b] - (N - sz[now]) * sz[now] << '\n';
            }
        }
    }

    return;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}