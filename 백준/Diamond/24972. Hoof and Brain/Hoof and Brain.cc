#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, Q;
set<int> graph[100005], rev[100005];
int rmv[100005], parent[100005];

int find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[a] = b;
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        rev[b].insert(a);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        if (graph[i].size() == 0) q.push(i);
    }

    while (q.size()) {
        int now = q.front();
        q.pop();
        rmv[now] = 1;
        for (int r: rev[now]) {
            graph[r].erase(now);
            if (graph[r].size() == 0) q.push(r);
        }
        rev[now].clear();
    }

    queue<pii> q2;

    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 1) {
            int nxt = *graph[i].begin();
            q2.push({i, nxt});

            graph[i].clear();
            rev[nxt].erase(i);
        }
    }

    while (q2.size()) {
        pii now = q2.front();
        q2.pop();

        int x = now.first, y = now.second;
        x = find(x), y = find(y);

        if (x == y) continue;

        if (rev[x].size() > rev[y].size()) swap(x, y);

        merge(x, y);
        for (int i: rev[x]) {
            graph[i].erase(x);
            graph[i].insert(y);
            rev[y].insert(i);

            if (graph[i].size() == 1) {
                int nxt = *graph[i].begin();
                q2.push({i, nxt});
                graph[i].clear();
                rev[nxt].erase(i);
            }
        }

        rev[x].clear();
    }

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (rmv[a] || rmv[b] || find(a) == find(b)) cout << "B";
        else cout << "H";
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