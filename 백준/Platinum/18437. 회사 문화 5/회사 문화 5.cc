#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector <int> tree[100005];
pii id[100005];
vector <int> seg, lazy;

void DFS(int node);
void update(int node, int start, int end, int left, int right, int val);
void update_lazy(int node, int start, int end);
int query(int node, int start, int end, int left, int right);


void solve() {
    cin >> N;

    seg.resize(4 * N);
    lazy.resize(4 * N);

    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        if (a) tree[a].push_back(i);
    }

    DFS(1);

    update(1, 1, N, 1, N, 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) update(1, 1, N, id[b].first +  1, id[b].second, 1);
        else if (a == 2) update(1, 1, N, id[b].first + 1, id[b].second, 2);
        else cout << query(1, 1, N, id[b].first + 1, id[b].second) << '\n';
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

void DFS(int node) {
    id[node].first = ++cnt;
    for (int i : tree[node]) DFS(i);
    id[node].second = cnt;
    return;
}

void update(int node, int start, int end, int left, int right, int val) {
    update_lazy(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        lazy[node] = val;
        update_lazy(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return;
}

void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        if (lazy[node] == 1) seg[node] = (end - start + 1);
        else seg[node] = 0;
        if (start != end) {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}
int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}