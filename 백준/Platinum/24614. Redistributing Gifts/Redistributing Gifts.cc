#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int arr[20][20];
int adj[20];
ll dp[20][(1 << 20)];
ll ans[(1 << 20)];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i] += (1 << arr[i][j]);
            if (arr[i][j] == i) break;
        }
    }

    ans[0] = 1;
    for (int i = 0; i < N; i++) dp[i][(1 << i)] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1 << i; j < 1 << (i + 1); j++) { // i가 포함된 상태
            for (int k = 0; k <= i; k++) { // 가장 마지막 방문이 k
                if (j & (1 << k)) {
                    ll val = dp[k][j];
                    for (int l = 0; l < i; l++) { // 다음 방문이 l
                        if (j & (1 << l)) continue;
                        if (adj[k] & (1 << l)) dp[l][(j + (1 << l))] += val;
                    }
                    if (adj[k] & (1 << i)) ans[j] += val; // 사이클의 마지막이 될 수 있을 때
                }
            }

            for (int k = i + 1; k < N; k++) dp[k][j + (1 << k)] += ans[j]; // 사이클이 끝나고, 다른 사이클 이어붙이기
        }
    }

    cin >> Q;
    while (Q--) {
        string S;
        cin >> S;
        ll a = 0, b = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'G') a += (1 << i);
            else b += (1 << i);
        }

        cout << ans[a] * ans[b] << '\n';
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