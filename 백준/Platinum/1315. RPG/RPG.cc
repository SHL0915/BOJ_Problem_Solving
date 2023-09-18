#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct quest {
    int s, i, p;
};

int N;
quest arr[55];
int clear[1005][1005], point[1005][1005], dp[1005][1005];

pii cal(int a, int b) {
    int cnt = 0, sum = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i].s <= a || arr[i].i <= b) {
            cnt++;
            sum += arr[i].p;
        }
    }
    return {cnt, sum + 2 - (a + b)};
}

int DP(int a, int b) {
    if (a == 1 && b == 1) return 1;
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    ret = 0;

    if (a > 1 && point[a - 1][b] > 0) ret |= DP(a - 1, b);
    if (b > 1 && point[a][b - 1] > 0) ret |= DP(a, b - 1);

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].s >> arr[i].i >> arr[i].p;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            pii c = cal(i, j);
            clear[i][j] = c.first;
            point[i][j] = c.second;
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (DP(i, j)) ans = max(ans, clear[i][j]);
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