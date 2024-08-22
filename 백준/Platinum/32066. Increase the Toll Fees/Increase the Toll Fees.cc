#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
vector <pair<ll, pii>> edge;
vector <pii> tree[100005];
int chk[200005], par[100005], pp[100005][20], level[100005], cost[100005][20];

void DFS(int node, int p, int lv) {
    level[node] = lv;
    pp[node][0] = p;
    for (int i = 1; i < 20; i++) pp[node][i] = pp[pp[node][i - 1]][i - 1], cost[node][i] = max(cost[node][i - 1], cost[pp[node][i - 1]][i - 1]);

    for (pii next : tree[node]) {
        if (next.first == p) continue;
        cost[next.first][0] = next.second;
        DFS(next.first, node, lv + 1);
    }
}

int LCA(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 19; i >= 0; i--) {
            if (level[pp[a][i]] >= level[b]) a = pp[a][i];
        }
    }
    int ret = a;
    if (a != b) {
        for (int i = 19; i >= 0; i--) {
            if (pp[a][i] != pp[b][i]) {
                a = pp[a][i];
                b = pp[b][i];
            }
            ret = pp[a][i];
        }
    }
    return ret;
}

ll find_max(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    int ret = 0;
    if (level[a] != level[b]) {
        for (int i = 19; i >= 0; i--) {
            if (level[pp[a][i]] > level[b]) {
                ret = max(ret, cost[a][i]), a = pp[a][i];
            }
        }
    }
    if (level[a] != level[b]) {
        ret = max(ret, cost[a][0]);
    }
    return ret;
}

void init() {
    for (int i = 1; i <= N; i++) par[i] = i;
}

int find(int a) {
    if (par[a] == a) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[find(a)] = find(b);
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({ c, {a, b} });
    }

    sort(edge.begin(), edge.end());

    init();

    priority_queue <pii, vector<pii>, greater<>> pq;
    ll a = 0, b = 0;
    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
        if (find(u) == find(v)) continue;
        chk[i] = 1;
        pq.push({ c, i });
        a += c;
        merge(u, v);
    }

    init();
    int cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (chk[i]) continue;
        int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
        if (find(u) == find(v)) continue;
        tree[u].push_back({ v, c });
        tree[v].push_back({ u, c });
        b += c;
        cnt++;
        merge(u, v);
    }

    if (cnt != N - 1) {
        cout << -1;
        return;
    }

    DFS(1, 1, 1);

    ll ans = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (!chk[i]) continue;
        int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
        int lca = LCA(u, v);
        ll M = max(find_max(u, lca), find_max(v, lca));
        ans += M - c + 1;
    }

    cout << ans << '\n';

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