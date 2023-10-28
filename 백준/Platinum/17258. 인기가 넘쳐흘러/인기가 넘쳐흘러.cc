#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, K, T;
int arr[305];
int dp[305][305][305];

int DP(int time, int add, int tot) {
    if (tot > K) return -INF;
    if (time == N + 1) return 0;
    int &ret = dp[time][add][tot];
    if (ret != -1) return ret;
    ret = 0;

    if (arr[time] >= T) ret = max(ret, 1 + DP(time + 1, 0, tot));
    else {
        if (arr[time] + add >= T) ret = max(ret, 1 + DP(time + 1, add, tot));
        else {
            ret = max(ret, DP(time + 1, add, tot));
            int cost = T - (arr[time] + add);
            ret = max(ret, 1 + DP(time + 1, add + cost, tot + cost));
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M >> K >> T;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a]++;
        arr[b]--;
    }

    for (int i = 1; i <= N + 1; i++) arr[i] += arr[i - 1];
    memset(dp, -1, sizeof(dp));

    cout << DP(1, 0, 0);
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