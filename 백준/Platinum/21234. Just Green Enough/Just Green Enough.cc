#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[505][505];
int A[505][505], B[505][505];

void solve() {
    cin >> N;
    memset(A, INF, sizeof(A));
    memset(B, INF, sizeof(B));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 100) A[i][j] = i;
            else if (arr[i][j] < 100) B[i][j] = i;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            A[j][i] = min(A[j][i], A[j + 1][i]);
            B[j][i] = min(B[j][i], B[j + 1][i]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a = INF, b = N;
            for (int k = j; k < N; k++) {
                a = min(a, A[i][k]);
                b = min(b, B[i][k]);
                if (a == INF || a >= b) continue;
                ans += (b - a);
            }
        }
    }

    cout << ans;

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