#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
vector<int> tree[250005];
pii ett[250005];
int seg[2 * 250005], level[250005];

void update(int pos, int v) {
    for (seg[pos += (N + 5)] += v; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += (N + 5), r += (N + 5); l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void DFS(int node, int par, int lv) {
    ett[node].first = ++cnt;
    update(cnt, lv);
    update(cnt + 1, -lv);
    level[node] = lv;
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node, lv + 1);
    }
    ett[node].second = cnt;
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1, 1, 0);
    
    cin >> M;
    for (int i = 0; i < N + M - 1; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            int a, b;
            cin >> a >> b;
            if (level[a] > level[b]) swap(a, b);
            update(ett[b].first, -1);
            update(ett[b].second + 1, 1);
        } else {
            int a;
            cin >> a;
            cout << query(1, ett[a].first) << '\n';
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