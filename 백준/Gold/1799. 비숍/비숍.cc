#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> graph[25];
int A[25], B[25], mark[25];

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
    for (int i = 0; i < 2 * N; i++) {
        if (A[i] == -1) {
            memset(mark, 0, sizeof(mark));
            ret += DFS(i);
        }
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a) graph[i + j].push_back(N - i - 1 + j);
        }
    }
    cout << Bipartite_Matching();
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