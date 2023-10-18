#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
map<string, int> convert;
int A[1005], B[1005], mark[1005];
vector<int> graph[1005];

int DFS(int now) {
    mark[now] = 1;
    for (int next: graph[now]) {
        if (B[next] == -1 || (mark[B[next]] == 0 && DFS(B[next]))) {
            A[now] = next;
            B[next] = now;
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        convert[s] = i;
    }
    
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            graph[i].push_back(convert[s]);
        }
    }
    
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            memset(mark, 0, sizeof(mark));
            cnt += DFS(i);
        }
    }
    
    if (cnt == N) cout << "YES";
    else cout << "NO\n" << cnt;
    
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