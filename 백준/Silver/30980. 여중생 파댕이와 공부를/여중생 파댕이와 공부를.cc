#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string arr[605];
string ans[605];

void f(int x, int y) {
    int a = arr[y + 1][x + 1] - '0', b = arr[y + 1][x + 3] - '0', c, t = 0;
    if (arr[y + 1][x + 6] == '.') c = arr[y + 1][x + 5] - '0', t = 0;
    else c = arr[y + 1][x + 6] - '0' + 10 * (arr[y + 1][x + 5] - '0'), t = 1;

    if (a + b == c) {
        if (!t) {
            for (int i = 0; i < 5; i++) ans[y][x + 1 + i] = '*', ans[y + 2][x + 1 + i] = '*';
            ans[y + 1][x] = ans[y + 1][x + 6] = '*';
        } else {
            for (int i = 0; i < 6; i++) ans[y][x + 1 + i] = '*', ans[y + 2][x + 1 + i] = '*';
            ans[y + 1][x] = ans[y + 1][x + 7] = '*';
        }
    } else {
        ans[y][x + 3] = ans[y + 1][x + 2] = ans[y + 2][x + 1] = '/';
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N * 3; i++) cin >> arr[i], ans[i] = arr[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) f(j * 8, i * 3);
    }

    for (int i = 0; i < N * 3; i++) cout << ans[i] << '\n';

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