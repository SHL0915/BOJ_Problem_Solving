#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, K;
int arr[105][105];

void solve() {
    cin >> N >> K;

    int cnt = 0;
    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < N; i++) {
        for (int j = i % 5; j < N; j += 5) {
            cout << (i + 1) << " " << (j + 1) << endl;
            string s;
            cin >> s;
            if (s[0] == 'm') arr[i][j] = 0;
            else {
                if (s[0] == 's') cnt++;
                arr[i][j] = 1;
            }
            if (cnt == K) return;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 1; l <= 5; l++) {
                        int x = i + dx[k] * l, y = j + dy[k] * l;
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        cout << (x + 1) << " " << (y + 1) << endl;
                        string s;
                        cin >> s;
                        if (s[0] == 's') cnt++;
                        if (cnt == K) return;
                    }
                }
            }
        }
    }

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}