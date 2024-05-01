#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[2005];
int dp[2005];

int DP(int n) {
    if (n <= 1) return 0;
    int &ret = dp[n];
    if (ret != -1) return ret;

    set<int> s;
    for (int i = 1; i < n; i++) {
        int nxt = DP(i);
        if ((n / i) % 2 == 0) nxt = 0;
        nxt ^= DP(n % i);
        s.insert(nxt);
    }

    int cnt = 0;
    for (int a: s) {
        if (a != cnt) break;
        else cnt++;
    }

    ret = cnt;
    return ret;
}

void solve() {
    cin >> N;
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ans ^= DP(arr[i]);
    }

    if (ans) cout << "First";
    else cout << "Second";

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