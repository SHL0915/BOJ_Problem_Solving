#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, sqrtN;
int arr[100005];
int cnt[355][10005];

void update(int idx, int v) {
    int p = arr[idx], bucket = idx / sqrtN;
    if (p > v) {
        for (int i = v; i < p; i++) cnt[bucket][i]++;
    } else {
        for (int i = p; i < v; i++) cnt[bucket][i]--;
    }
    arr[idx] = v;
    return;
}

int query(int l, int r, int k) {
    int ret = 0;
    while (l % sqrtN && l <= r) {
        if (arr[l++] > k) ret++;
    }
    while (l + sqrtN <= r) {
        ret += cnt[l / sqrtN][10000] - cnt[l / sqrtN][k];
        l += sqrtN;
    }
    while (l <= r) {
        if (arr[l++] > k) ret++;
    }
    return ret;
}

void solve() {
    cin >> N;
    sqrtN = min(N, 355);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        cnt[i / sqrtN][arr[i]]++;
    }

    for (int i = 0; i <= (N / sqrtN); i++) {
        for (int j = 1; j <= 10000; j++) cnt[i][j] += cnt[i][j - 1];
    }

    cin >> M;
    while (M--) {
        int a, i, v, j, k;
        cin >> a;
        if (a == 1) {
            cin >> i >> v;
            update(i, v);
        } else {
            cin >> i >> j >> k;
            cout << query(i, j, k) << '\n';
        }
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