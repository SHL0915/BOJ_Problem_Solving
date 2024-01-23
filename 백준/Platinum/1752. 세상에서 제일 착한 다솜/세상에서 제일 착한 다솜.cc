#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const short INF = 10005;

int R, C;
int N;
pii arr[5005];
map<int, int> grid[5005];
short dp[5005][5005];

short DP(int now, int prev) {
    if (now == N + 1) return 0;
    short ret = dp[now][prev];
    if (ret != -1) return ret;
    ret = -INF;
    int x = arr[now].second, y = arr[now].first;
    if (prev) {
        int dy = arr[now].first - arr[prev].first;
        int dx = arr[now].second - arr[prev].second;
        if (x + dx < 1 || x + dx > C || y + dy < 1 || y + dy > R) return ret = 1;
        if (grid[y + dy].count(x + dx)) return ret = 1 + DP(grid[y + dy][x + dx], now);
        else return ret = -INF;
    } else {
        for (int i = now + 1; i <= N; i++) {
            int dy = arr[i].first - arr[now].first;
            int dx = arr[i].second - arr[now].second;
            if (x - dx < 1 || x - dx > C || y - dy < 1 || y - dy > R) ret = max(ret, (short) (1 + DP(i, now)));
        }
        return ret;
    }
}

void solve() {
    cin >> R >> C >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) grid[arr[i].first][arr[i].second] = i;
    memset(dp, -1, sizeof(dp));

    short ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, DP(i, 0));

    if (ans < 3) cout << 0;
    else cout << ans;

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