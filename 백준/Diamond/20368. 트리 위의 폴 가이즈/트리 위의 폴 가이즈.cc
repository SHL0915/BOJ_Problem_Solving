#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, P, Q, root;
vector<int> tree[200005], path, A, B;
int arr[200005], p[200005];
vector<int> _seg[2];

void update(int pos, int v, vector<int> &seg) {
    for (seg[pos += N] = v; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r, vector<int> &seg) {
    r++;
    int ret = -1e9;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

int find_path(int node, int par, vector<int> &v, int t) {
    v.push_back(node);
    if (node == t) return 1;
    int ret = 0;
    for (int next: tree[node]) {
        if (next == par) continue;
        ret |= find_path(next, node, v, t);
    }
    if (!ret) v.pop_back();
    return ret;
}

int find_farthest(int node, int par) {
    int &ret = arr[node];
    ret = 1;
    for (int next: tree[node]) {
        if (next == par) continue;
        p[next] = node;
        ret = max(ret, 1 + find_farthest(next, node));
    }
    return ret;
}

int DFS(int k, int t) {
    if (!t) {
        int ret = -1e9;
        int a = A[k], b = B[k];
        if (k < A.size() && A[k + 1] != b) ret = max(ret, DFS(k, t ^ 1));
        ret = max(ret, query(k, k, _seg[0]) - query(k, path.size() - 2 - k, _seg[1]));
        return ret;
    } else {
        int ret = 1e9;
        int a = A[k + 1], b = B[k];
        if (k < B.size() && B[k + 1] != b) ret = min(ret, DFS(k + 1, t ^ 1));
        ret = min(ret, query(k + 1, path.size() - 2 - k, _seg[0]) - query(k, k, _seg[1]));
        return ret;
    }
}

void solve() {
    cin >> N >> P >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    find_path(P, P, path, Q);
    root = path[path.size() / 2];
    find_path(P, P, A, root);
    find_path(Q, Q, B, root);
    find_farthest(root, root);
    
    set<int> s;
    for (int i = 0; i < path.size(); i++) s.insert(path[i]);
    
    for (int i = 0; i < 2; i++) _seg[i].resize(2 * N + 5, -1e9);
    
    int M = 1;
    for (int next: tree[P]) {
        if (s.count(next)) continue;
        M = max(M, arr[next] + 1);
    }
    update(0, M, _seg[0]);
    for (int i = 1; i < path.size() - 1; i++) {
        int now = path[i];
        M = 1;
        for (int next: tree[now]) {
            if (s.count(next)) continue;
            M = max(M, arr[next] + 1);
        }
        update(i, M + i, _seg[0]);
    }
    
    reverse(path.begin(), path.end());
    M = 1;
    for (int next: tree[Q]) {
        if (s.count(next)) continue;
        M = max(M, arr[next] + 1);
    }
    update(0, M, _seg[1]);
    for (int i = 1; i < path.size() - 1; i++) {
        int now = path[i];
        M = 1;
        for (int next: tree[now]) {
            if (s.count(next)) continue;
            M = max(M, arr[next] + 1);
        }
        update(i, M + i, _seg[1]);
    }
    
    cout << DFS(0, 0);
    
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