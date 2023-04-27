#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector <int> graph[200001];
queue <pii> q;
int mark[200001];

int DFS(int node, int par, int lv);
void BFS();

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int a, b, c;
    cin >> a >> b >> c;

    memset(mark, -1, sizeof(mark));
    q.push({ b, 0 });
    q.push({ c, 0 });
    while (q.size()) BFS();

    int ans = DFS(a, a, 0);

    if (ans) cout << "YES";
    else cout << "NO";
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

int DFS(int node, int par, int lv) {
    if (graph[node].size() == 1) {
        if (mark[node]) return 1;
        else return 0;
    }
    if (lv >= mark[node]) return 0;

    int ret = 0;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] == par) continue;
        ret |= DFS(graph[node][i], node, lv + 1);
    }

    return ret;
}

void BFS() {
    pii f = q.front(); q.pop();
    int now = f.first;
    int d = f.second;
    if (mark[now] != -1) return;
    mark[now] = d;

    for (int i = 0; i < graph[now].size(); i++) q.push({ graph[now][i], d + 1 });

    return;
}