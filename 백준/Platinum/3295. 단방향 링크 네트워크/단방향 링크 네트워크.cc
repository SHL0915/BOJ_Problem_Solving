#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[1005];
int A[1005], B[1005], mark[1005];

void init();

void clearMark();

int DFS(int node);

void solve() {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            clearMark();
            ans += DFS(i);
        }
    }

    cout << ans << '\n';
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

void init() {
    for (int i = 0; i < N; i++) {
        graph[i].clear();
        A[i] = -1;
        B[i] = -1;
    }
    return;
}

void clearMark() {
    for (int i = 0; i < N; i++) mark[i] = 0;
    return;
}

int DFS(int node) {
    mark[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (B[next] == -1) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (mark[B[next]] == 0 && DFS(B[next])) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }

    return 0;
}