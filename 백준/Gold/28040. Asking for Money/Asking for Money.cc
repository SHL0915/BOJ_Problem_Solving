#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, flag;
vector<int> graph[1005];
pii parent[1005];
int mark[1005][3];

void DFS(int node, int org);

void chk(int node, int org);

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> parent[i].first >> parent[i].second;
        graph[parent[i].first].push_back(i);
        graph[parent[i].second].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        flag = 0;
        memset(mark, 0, sizeof(mark));
        mark[i][0] = mark[i][1] = 1;

        DFS(parent[i].first, 0);
        DFS(parent[i].second, 1);

        chk(i, i);
        if (flag) cout << "Y";
        else cout << "N";
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

void DFS(int node, int org) {
    if (mark[node][org]) return;
    mark[node][org] = 1;
    for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i], org);
    return;
}

void chk(int node, int org) {
    if (mark[node][2]) return;
    mark[node][2] = 1;
    if (node != org && (mark[node][0] == 1 && mark[node][1] == 1)) flag = 1;
    for (int i = 0; i < graph[node].size(); i++) chk(graph[node][i], org);
    return;
}