#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[2005];
int type[2005], A[2005], B[2005], mark[2005];

int DFS(int node, int org) {
    mark[node] = org;
    for (int next: graph[node]) {
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
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        char c;
        cin >> c;
        if (c == 'c') type[a] = 1;
        else type[a] = 2;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (type[a] == 1) graph[a].push_back(b);
        else graph[b].push_back(a);
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (A[i] == -1) ans += DFS(i, i);
    }

    cout << N - ans;
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