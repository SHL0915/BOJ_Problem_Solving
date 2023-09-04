#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt;
int adj[3005][3005];
int mark[3005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (mark[i] || mark[j]) continue;
            if (adj[i][j] == 0) {
                mark[i] = 1;
                mark[j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (cnt == N / 3) break;
        if (mark[i] == 0) {
            cout << i << " ";
            cnt++;
        }
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