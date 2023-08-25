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
        if (graph[i].size() <= 1) q.push(i);
    }

    while (q.size()) {
        int now = q.front();
        now = find(now);
        q.pop();
        if (graph[now].size() == 0) {
            for (int r: rev[now]) {
                r = find(r);
                graph[r].erase(now);
                if (graph[r].size() <= 1) q.push(r);
            }
            rev[now].clear();
        } else if (graph[now].size() == 1) {
            int nxt = *graph[now].begin();
            nxt = find(nxt);
            if (now == nxt) continue;

            graph[now].clear();
            rev[nxt].erase(now);

            if (graph[now].size() + rev[now].size() > graph[nxt].size() + rev[nxt].size()) swap(now, nxt);

            for (int i: graph[now]) {
                if (now == i) {
                    graph[nxt].insert(nxt);
                    continue;
                }
                rev[i].erase(now);
                rev[i].insert(nxt);
                graph[nxt].insert(i);
            }

            for (int i: rev[now]) {
                if (now == i) {
                    rev[nxt].insert(nxt);
                    continue;
                }
                graph[i].erase(now);
                graph[i].insert(nxt);
                rev[nxt].insert(i);
                if (graph[i].size() <= 1) q.push(i);
            }
            graph[now].clear();
            rev[now].clear();

            merge(now, nxt);
            if (graph[nxt].size() == 1) q.push(nxt);
        }
    }

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if (graph[a].size() == 0 || graph[b].size() == 0 || a == b) cout << "B";
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