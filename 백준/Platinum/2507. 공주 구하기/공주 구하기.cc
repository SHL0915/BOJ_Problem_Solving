#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int mod = 1000;

struct island {
    int dist, str, t;
};

int N;
island arr[505];
int dp[505][505], temp[505][505];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i].dist >> arr[i].str >> arr[i].t;
    temp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < i; k++) dp[j][k] = temp[j][k];
        }
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < i; k++) {
                if (temp[j][k] == 0) continue;
                int fdist = arr[i].dist - arr[j].dist;
                int bdist = arr[i].dist - arr[k].dist;

                if (fdist <= arr[j].str) dp[i][k] = (dp[i][k] + temp[j][k]) % mod;
                if (arr[i].t && bdist <= arr[i].str) dp[j][i] = (dp[j][i] + temp[j][k]) % mod;
            }
        }
        swap(dp, temp);
    }

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        int dist = arr[N].dist - arr[i].dist;
        if (dist <= arr[i].str) ans += temp[i][N];
        //if (dist <= arr[N].str) ans += temp[N][i];
        ans %= mod;
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