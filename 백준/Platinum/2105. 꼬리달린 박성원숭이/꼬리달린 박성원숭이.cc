#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
pii edge[200001];
vector <int> graph[200001];
int parent[200001];
set <int> s[200001];
int mark[200001];
pair<pii, int> query[400001];
map <pii, int> m;
set <pii> del;

int Find(int a);
void Union(int a, int b);
void DFS(int node);

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        s[i].insert(i);
        int l, r;
        cin >> l >> r;
        edge[i] = { l,r };
        if (l != -1) {
            m[{min(i, l), max(i, l)}]++;
            graph[i].push_back(l);
            graph[l].push_back(i);
        }
        if (r != -1) {
            m[{min(i, r), max(i, r)}]++;
            graph[i].push_back(r);
            graph[r].push_back(i);
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (b == 1) {
            if (edge[a].first == -1) continue;
            m[{min(a, edge[a].first), max(a, edge[a].first)}]--;
            if (m[{min(a, edge[a].first), max(a, edge[a].first)}] == 0) {
                query[cnt++] = { { a, edge[a].first }, i };
                del.insert({ a, edge[a].first });
                del.insert({ edge[a].first, a });
            }
        }
        else if (b == 2) {
            if (edge[a].second == -1) continue;
            m[{min(a, edge[a].second), max(a, edge[a].second)}]--;
            if (m[{min(a, edge[a].second), max(a, edge[a].second)}] == 0) {
                query[cnt++] = { { a, edge[a].second } , i };
                del.insert({ a, edge[a].second });
                del.insert({ edge[a].second, a });
            }
        }
    }
    for (int i = 1; i <= N; i++) if (mark[i] == 0) DFS(i);
    for (auto i = s[1].begin(); i != s[1].end(); i++) mark[*i] = -1;
    for (int i = cnt - 1; i >= 0; i--) {
        int a = query[i].first.first, b = query[i].first.second, t = query[i].second;
        a = Find(a);
        b = Find(b);
        if (a == b) continue;
        if (a == 1) {
            for (auto i = s[b].begin(); i != s[b].end(); i++) mark[*i] = t;
        }
        if (b == 1) {
            for (auto i = s[a].begin(); i != s[a].end(); i++) mark[*i] = t;
        }
        Union(a, b);
    }
    for (int i = 1; i <= N; i++) cout << mark[i] << '\n';
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

int Find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (a > b) {
        parent[a] = b;
        if (s[b].size() < s[a].size()) swap(s[b], s[a]);
        for (auto i = s[a].begin(); i != s[a].end(); i++) s[b].insert(*i);
    }
    else {
        parent[b] = a;
        if (s[a].size() < s[b].size()) swap(s[b], s[a]);
        for (auto i = s[b].begin(); i != s[b].end(); i++) s[a].insert(*i);
    }
    return;
}

void DFS(int node) {
    if (mark[node]) return;
    mark[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (del.count({ node, graph[node][i] })) continue;
        Union(node, graph[node][i]);
        DFS(graph[node][i]);
    }
    return;
}