#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 1005;

int N, M;
vector<int> graph[SZ];
int A[SZ], B[SZ], mark[SZ];

int DFS(int node) {
    mark[node] = 1;
    for (int next: graph[node]) {
        if (B[next] == -1) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }

    for (int next: graph[node]) {
        if (mark[B[next]] == 0 && DFS(B[next])) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }

    return 0;
}

int Bipartite_Matching() {
    int ret = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            memset(mark, 0, sizeof(mark));
            ret += DFS(i);
        }
    }
    return ret;
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) graph[i].clear();

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cout << Bipartite_Matching() << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}