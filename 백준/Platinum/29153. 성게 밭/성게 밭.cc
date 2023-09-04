#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[15005], ngraph[15005], bipartite[15005];
vector<pii> edge;
int mark[15005], A[15005], B[15005];

void make_bipartite(int node) {
    for (int next: ngraph[node]) {
        if (mark[next] != -1) continue;
        mark[next] = mark[node] ^ 1;
        make_bipartite(next);
    }
    return;
}

int DFS(int node, int org) {
    mark[node] = org;
    for (int next: bipartite[node]) {
        if (B[next] == -1 || mark[B[next]] != org && DFS(B[next], org)) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int tot = 0;

    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 2) {
            edge.push_back({graph[i][0], graph[i][1]});
            ngraph[graph[i][0]].push_back(graph[i][1]);
            ngraph[graph[i][1]].push_back(graph[i][0]);
        }
        if (graph[i].size() >= 3) tot++;
    }

    memset(mark, -1, sizeof(mark));

    for (int i = 1; i <= N; i++) {
        if (mark[i] == -1) {
            mark[i] = 1;
            make_bipartite(i);
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].first, b = edge[i].second;
        if (mark[a] == 0) swap(a, b);
        bipartite[a].push_back(b);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    memset(mark, 0, sizeof(mark));

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == -1) cnt += DFS(i, i);
    }

    cout << tot - cnt;
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