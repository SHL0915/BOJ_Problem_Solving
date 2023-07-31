#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
vector<pair<pii, pii>> edge;
set<pii> tree[2005];
pii e[3005];
int parent[2005], mark[3005];
pii p[2005];

int Find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = Find(parent[a]);
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (a > b) parent[a] = b;
    else parent[b] = a;
    return;
}

void DFS(int node, int par, int id) {
    p[node] = {par, id};
    for (pii i: tree[node]) {
        int next = i.first;
        int idx = i.second;
        if (next == par) continue;
        DFS(next, node, idx);
    }
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{c, i},
                        {a, b}});
        e[i] = {a, b};

        if (i <= N - 1) {
            tree[a].insert({b, i});
            tree[b].insert({a, i});
        }
    }

    sort(edge.begin(), edge.end());

    int cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (cnt == N - 1) break;
        int a = edge[i].second.first, b = edge[i].second.second;
        int idx = edge[i].first.second;
        if (Find(a) == Find(b)) continue;
        Merge(a, b);
        mark[idx] = 1;
        cnt++;
    }

    vector<pii> ans;
    for (int i = N; i <= M; i++) {
        if (mark[i] == 0) continue;
        int a = e[i].first, b = e[i].second;
        DFS(a, a, -1);
        int now = b;

        while (now != a) {
            pii next = p[now];
            if (mark[next.second] == 0) {
                ans.push_back({next.second, i});
                tree[now].erase(next);
                tree[next.first].erase({now, next.second});
                tree[a].insert({b, i});
                tree[b].insert({a, i});
                break;
            }
            now = next.first;
        }
    }

    cout << ans.size() << '\n';
    for (pii i: ans) cout << i.first << " " << i.second << '\n';

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