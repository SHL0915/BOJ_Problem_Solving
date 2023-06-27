#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, flag;
vector<pii> graph[100005];
map<pii, int> edge;
int rev[1000005];
int mark[100005], parent[100005], ans[100005];
int chk[100005];
set<int> s[100005];
vector<int> cycle;

void DFS(int node, int par);
void f(int node, int par);

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        edge[{a, b}] = i;
        edge[{b, a}] = i;
        rev[i] = c;
    }

    mark[1] = 1;
    DFS(1, -1);

    for (int i = 0; i < cycle.size(); i++) {
        int now = cycle[i], next = cycle[(i + 1) % cycle.size()];
        int idx = edge[{now, next}];
        ans[idx] = now;
        s[next].insert(rev[idx]);
        f(next, next);
    }

    if (flag == 0) {
        for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
        return;
    }

    flag = 0;
    for (int i = 1; i <= N; i++) s[i].clear();

    for (int i = 0; i < cycle.size(); i++) {
        int next = cycle[i], now = cycle[(i + 1) % cycle.size()];
        int idx = edge[{now, next}];
        ans[idx] = now;
        s[next].insert(rev[idx]);
        f(next, next);
    }

    if (flag == 0) {
        for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
        return;
    }

    cout << "impossible";
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

void DFS(int node, int par) {
    parent[node] = par;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].first;
        if (next == par) continue;
        if (mark[next] && chk[next] == 0) {
            int now = node;
            cycle.push_back(next);
            chk[next] = 1;
            while (now != next) {
                cycle.push_back(now);
                chk[now] = 1;
                now = parent[now];
            }
        }
        if (mark[next]) continue;
        mark[next] = 1;
        DFS(next, node);
    }

    return;
}

void f(int node, int par) {
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].first;
        if (next == par) continue;
        if (chk[next]) continue;
        int idx = edge[{node, next}];
        int val = rev[idx];

        if (s[node].count(val)) {
            flag = 1;
            return;
        }

        ans[idx] = next;
        s[node].insert(val);
        f(next, node);
    }

    return;
}