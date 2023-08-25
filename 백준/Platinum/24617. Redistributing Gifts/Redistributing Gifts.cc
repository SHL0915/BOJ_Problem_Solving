#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[505][505];
int adj[505][505];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> arr[i][j];
    }

    memset(adj, INF, sizeof(adj));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][arr[i][j]] = 0;
            if (arr[i][j] == i) break;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int now = arr[i][j];
            if(adj[i][now] == 0 && adj[now][i] == 0) {
                cout << now << '\n';
                break;
            }
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