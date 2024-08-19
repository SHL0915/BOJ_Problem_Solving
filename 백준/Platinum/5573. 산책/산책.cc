#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, W, N;
int arr[1005][1005];
int cnt[1005][1005];

void solve() {
    cin >> H >> W >> N;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) cin >> arr[i][j];
    }

    cnt[1][1] = N - 1;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (cnt[i][j] % 2) {
                int a = cnt[i][j] / 2;
                int b = cnt[i][j] - a;
                if (arr[i][j]) swap(a, b);
                cnt[i][j + 1] += a;
                cnt[i + 1][j] += b;
            } else {
                cnt[i + 1][j] += cnt[i][j] / 2;
                cnt[i][j + 1] += cnt[i][j] / 2;
            }
            if (cnt[i][j] % 2) arr[i][j] ^= 1;
        }
    }

    int x = 1, y = 1;

    while (x <= W && y <= H) {
        if (arr[y][x]) x++;
        else y++;
    }

    cout << y << " " << x;

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