#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<uint, uint>;
const uint SZ = 500005;

uint N, Q, cnt;
vector <uint> graph[SZ], tree[SZ];
uint mark[SZ], parent[SZ], level[SZ], sz[SZ], head[SZ];
pii id[SZ];
vector <uint> seg, lazy[2];

void Find_Child(uint node);
void DFS(uint node, uint lv);
void ETT(uint node);
void update(uint a, uint b, uint sum, uint mul);
void update_lazy(uint node, uint start, uint end);
void update_seg(uint node, uint start, uint end, uint left, uint right, uint sum, uint mul);
uint query_seg(uint node, uint start, uint end, uint left, uint right);
uint query(uint a, uint b);

void solve() {
    cin >> N >> Q;

    seg.resize(4 * N + 5);
    lazy[0].resize(4 * N + 5);
    lazy[1].resize(4 * N + 5, 1);

    for (int i = 0; i < N - 1; i++) {
        uint a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    Find_Child(1);
    DFS(1, 1);

    head[1] = 1;
    ETT(1);

    for (int i = 0; i < Q; i++) {
        uint a; cin >> a;
        if (a == 1) {
            uint x, v;
            cin >> x >> v;
            update_seg(1, 1, N, id[x].first, id[x].second, v, 1);
        }
        else if (a == 2) {
            uint x, y, v;
            cin >> x >> y >> v;
            update(x, y, v, 1);
        }
        else if (a == 3) {
            uint x, v;
            cin >> x >> v;
            update_seg(1, 1, N, id[x].first, id[x].second, 0, v);
        }
        else if (a == 4) {
            uint x, y, v;
            cin >> x >> y >> v;
            update(x, y, 0, v);
        }
        else if (a == 5) {
            uint x; cin >> x;
            cout << query_seg(1, 1, N, id[x].first, id[x].second) << '\n';
        }
        else {
            uint x, y;
            cin >> x >> y;
            cout << query(x, y) << '\n';
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

void Find_Child(uint node) {
    mark[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        uint next = graph[node][i];
        if (mark[next]) continue;
        tree[node].push_back(graph[node][i]);
        Find_Child(next);
    }
    return;
}

void DFS(uint node, uint lv) {
    sz[node] = 1;
    level[node] = lv;
    for (int i = 0; i < tree[node].size(); i++) {
        uint& next = tree[node][i];
        parent[next] = node;
        DFS(next, lv + 1);
        sz[node] += sz[next];
        if (sz[next] > sz[tree[node][0]]) swap(next, tree[node][0]);
    }
    return;
}

void ETT(uint node) {
    cnt++;
    id[node].first = cnt;
    for (int i = 0; i < tree[node].size(); i++) {
        uint next = tree[node][i];
        if (i == 0) head[next] = head[node];
        else head[next] = next;
        ETT(next);
    }
    id[node].second = cnt;
    return;
}

void update(uint a, uint b, uint sum, uint mul) {
    while (head[a] != head[b]) {
        if (level[head[a]] < level[head[b]]) swap(a, b);
        uint st = head[a];
        update_seg(1, 1, N, id[st].first, id[a].first, sum, mul);
        a = parent[st];
    }
    if (level[a] > level[b]) swap(a, b);
    update_seg(1, 1, N, id[a].first, id[b].first, sum, mul);
    return;
}

void update_lazy(uint node, uint start, uint end) {
    uint& s = lazy[0][node];
    uint& m = lazy[1][node];
    if (s == 0 && m == 1) return;
    seg[node] = seg[node] * m + (end - start + 1) * s;
    if (start != end) {
        lazy[0][node * 2] *= m;
        lazy[0][node * 2] += s;
        lazy[1][node * 2] *= m;

        lazy[0][node * 2 + 1] *= m;
        lazy[0][node * 2 + 1] += s;
        lazy[1][node * 2 + 1] *= m;
    }

    s = 0; m = 1;
    return;
}

void update_seg(uint node, uint start, uint end, uint left, uint right, uint sum, uint mul) {
    update_lazy(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        lazy[0][node] *= mul;
        lazy[0][node] += sum;
        lazy[1][node] *= mul;
        update_lazy(node, start, end);
        return;
    }
    uint mid = (start + end) / 2;
    update_seg(node * 2, start, mid, left, right, sum, mul);
    update_seg(node * 2 + 1, mid + 1, end, left, right, sum, mul);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return;
}

uint query_seg(uint node, uint start, uint end, uint left, uint right) {
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return seg[node];
    uint mid = (start + end) / 2;
    return (query_seg(node * 2, start, mid, left, right) + query_seg(node * 2 + 1, mid + 1, end, left, right));
}

uint query(uint a, uint b) {
    uint ret = 0;
    while (head[a] != head[b]) {
        if (level[head[a]] < level[head[b]]) swap(a, b);
        uint st = head[a];
        ret += query_seg(1, 1, N, id[st].first, id[a].first);
        a = parent[st];
    }
    if (level[a] > level[b]) swap(a, b);
    ret += query_seg(1, 1, N, id[a].first, id[b].first);
    return ret;
}