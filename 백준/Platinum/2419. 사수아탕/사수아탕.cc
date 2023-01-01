#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[333][333][2];
bool v[333][333][2];
vector<int> pos;

// 실험용 코드: 출처 https://egod1537.tistory.com/9

int dst(int s, int e) {
    return abs(pos[s] - pos[e]);
}

int solve(int l, int r, int k, int w) {
    if (w == 0) return 0;
    if (l == 0 && r == n) return 0;

    int& ret = dp[l][r][k];
    if (v[l][r][k]) return ret;

    int now = (k) ? r : l;
    if (l > 0)
        ret = max(ret, solve(l - 1, r, 0, w - 1) - w * dst(now, l - 1) + m);

    if (r < n)
        ret = max(ret, solve(l, r + 1, 1, w - 1) - w * dst(now, r + 1) + m);

    v[l][r][k] = true;
    return ret;
}

int main() {
    cin >> n >> m;

    pos.resize(n);
    bool isZero = false;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
        if (pos[i] == 0) isZero = true;
    }

    if (!isZero)
        pos.push_back(0);
    else
        n--;

    sort(pos.begin(), pos.end());
    int idx = lower_bound(pos.begin(), pos.end(), 0) - pos.begin();

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        memset(dp, 0, sizeof(dp));
        memset(v, 0, sizeof(v));
        int k = solve(idx, idx, 0, i);
        if (isZero)
            k += m;

        ans = max(ans, k);
    }

    cout << ans;
    return 0;
}