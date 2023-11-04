#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];
vector<int> tree[200005], graph[200005];
ll par[200005][25], level[200005], dp[200005], parent[200005];

int find(int a) {
    if (parent[a] == a) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a < b) parent[a] = b;
    else parent[b] = a;
    return;
}

void DFS(int node, int p, int lv) {
    par[node][0] = p;
    level[node] = lv;
    for (int i = 1; i <= 20; i++) par[node][i] = par[par[node][i - 1]][i - 1];
    for (int next: tree[node]) {
        if (next == p) continue;
        DFS(next, node, lv + 1);
    }
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

ll dist(int a, int b) {
    ll ret = 0;
    if (level[a] < level[b]) swap(a, b);
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (level[par[a][i]] > level[b]) {
                ret += (1LL << i);
                a = par[a][i];
            }
        }
        ret++;
    }
    return ret;
}

ll DP(int now) {
    if (now == N) return 0;
    ll &ret = dp[now];
    if (ret != -1) return ret;
    for (int next: graph[now]) {
        int lca = LCA(now, next);
        ret = max(ret, dist(now, lca) + dist(next, lca) + DP(next));
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i], parent[i] = i;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[arr[a]].push_back(arr[b]);
        tree[arr[b]].push_back(arr[a]);
    }

    DFS(N, N, 1);

    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int a: tree[i]) {
            if (a > i) continue;
            if (i != find(a)) {
                graph[find(a)].push_back(i);
                merge(i, a);
            }
        }
    }

    for (int i = 1; i <= N; i++) ans = max(ans, DP(i));

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