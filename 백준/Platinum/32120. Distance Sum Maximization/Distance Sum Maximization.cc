#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, r1, r2, Q;
vector <int> tree[300005];
int dist[300005], arr[300005], par[300005];
vector <int> route;
int seg[1200505];

void update(int n, int s, int e, int idx, int v) {
    if(idx > e || idx < s) return;
    if(s == e) {
        seg[n] = max(seg[n], v);
        return;
    }
    int m = (s + e) / 2;
    update(n * 2, s, m, idx, v);
    update(n * 2 + 1, m + 1, e, idx, v);
    seg[n] = max(seg[2*n], seg[2*n+1]);
    return;
}

int query(int n, int s, int e, int l, int r) {
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return seg[n];
    int m = (s + e) / 2;
    return max(query(n * 2, s, m, l, r), query(n * 2 + 1, m + 1, e, l, r));
}

void find_root(int node, int par, int d) {
    dist[node] = d;
    for(int next : tree[node]) {
        if(next == par) continue;
        find_root(next, node, d + 1);
    }
    return;
}

int find_route(int node, int par) {
    if(node == r2) {
        route.push_back(node);
        return 1;
    }
    
    int ret = 0;
    for(int next : tree[node]) {
        if(next == par) continue;
        ret |= find_route(next, node);
    }

    if(ret) route.push_back(node);
    return ret;
}

void DFS(int node, int p, int pp, int d) {
    par[node] = pp;
    dist[node] = d;
    for(int next : tree[node]) {
        if(next == p) continue;
        if(arr[next]) continue;
        DFS(next, node, pp, d + 1);
    }
    return;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    find_root(1, 1, 1);
    int M = -1;
    for(int i = 1; i <= N; i++) M = max(M, dist[i]);
    for(int i = 1; i <= N; i++) {
        if(dist[i] == M) r1 = i;
    }

    find_root(r1, r1, 1);
    M = -1;
    for(int i = 1; i <= N; i++) M = max(M, dist[i]);
    for(int i = 1; i <= N; i++) {
        if(dist[i] == M) r2 = i;
    }
    
    find_route(r1, r1);

    for(int i = 0; i < route.size(); i++) arr[route[i]] = i + 1;

    for(int i = 0; i < route.size(); i++) {
        DFS(route[i], route[i], arr[route[i]], 0);
    }

    for(int i = 1; i <= N; i++) {
        update(1, 1, N, par[i], dist[i]);
    }

    cin >> Q;
    while(Q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        ans += dist[a] + dist[b];
        a = par[a], b = par[b];
        if(a > b) swap(a, b);

        int ret = 0;
        ret = max({abs(a - 1) + abs(b - 1), abs((int)route.size() - a) + abs((int)route.size() - b), b-a + 2 * query(1, 1, N, a + 1, b - 1)});
        cout << ans + ret << '\n';
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;
}