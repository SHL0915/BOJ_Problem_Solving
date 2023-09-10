#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, e_cnt;
map<pii, int> edgeId;
vector<pair<pii, pii>> edge;
vector<pii> graph[100005], tree[100005];
pii id[100005];
int parent[100005], head[100005], mst[300005], mark[100005], sz[100005], par[100005], level[100005], edge_id[300005];
ll seg[400005], lazy[400005], cost[300005];

int find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(a)] = find(b);
    return;
}

void update_lazy(int n, int s, int e) {
    if (lazy[n] != INF) {
        seg[n] = min(seg[n], lazy[n]);
        if (s != e) {
            lazy[n * 2] = min(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = min(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = INF;
    }
    return;
}

void update(int n, int s, int e, int l, int r, ll v) {
    update_lazy(n, s, e);
    if (l > e || r < s) return;
    else if (l <= s && e <= r) {
        lazy[n] = min(lazy[n], v);
        update_lazy(n, s, e);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, l, r, v);
    update(n * 2 + 1, m + 1, e, l, r, v);
    return;
}

ll query(int n, int s, int e, int l, int r) {
    update_lazy(n, s, e);
    if (l > e || r < s) return INF;
    else if (l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return min(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

void make_tree(int node) {
    mark[node] = 1;
    for (pii next: graph[node]) {
        if (mark[next.first]) continue;
        tree[node].push_back(next);
        make_tree(next.first);
    }
    return;
}

void DFS(int node, int lv) {
    sz[node] = 1;
    level[node] = lv;
    for (int i = 0; i < tree[node].size(); i++) {
        pii &next = tree[node][i];
        par[next.first] = node;
        DFS(next.first, lv + 1);
        sz[node] += sz[next.first];
        if (sz[next.first] > sz[tree[node][0].first]) swap(next, tree[node][0]);
    }
    return;
}

void ETT(int node) {
    id[node].first = ++e_cnt;
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        if (i == 0) head[next] = head[node];
        else head[next] = next;
        ETT(next);
        edge_id[edgeId[{node, next}]] = id[next].first;
    }
    id[node].second = e_cnt;
    return;
}

void hld(int a, int b, ll v) {
    while (head[a] != head[b]) {
        if (level[head[a]] < level[head[b]]) swap(a, b);
        int st = head[a];
        update(1, 1, N, id[st].first, id[a].first, v);
        a = par[st];
    }
    if (level[a] > level[b]) swap(a, b);
    update(1, 1, N, id[a].first + 1, id[b].first, v);
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{c, i},
                        {a, b}});
        cost[i] = c;
    }
    sort(edge.begin(), edge.end());

    ll sum = 0, cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (cnt == N - 1) break;
        ll a = edge[i].second.first, b = edge[i].second.second, c = edge[i].first.first, idx = edge[i].first.second;
        if (find(a) == find(b)) continue;
        sum += c;
        mst[idx] = 1;
        merge(a, b);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        edgeId[{a, b}] = idx;
        edgeId[{b, a}] = idx;
        cnt++;
    }

    memset(seg, 0x3f, sizeof(seg));
    memset(lazy, 0x3f, sizeof(lazy));

    make_tree(1);
    DFS(1, 1);
    ETT(1);

    for (int i = 0; i < edge.size(); i++) {
        if (mst[edge[i].first.second]) continue;
        ll a = edge[i].second.first, b = edge[i].second.second, c = edge[i].first.first;
        hld(a, b, c);
    }

    for (int i = 0; i < M; i++) {
        if (mst[i] == 0) cout << sum << '\n';
        else {
            int idx = edge_id[i];
            if (query(1, 1, N, idx, idx) == INF) cout << -1 << '\n';
            else cout << sum - cost[i] + query(1, 1, N, idx, idx) << '\n';
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
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}