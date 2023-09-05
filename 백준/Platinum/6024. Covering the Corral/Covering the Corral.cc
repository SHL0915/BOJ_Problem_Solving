#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll C, M;
pii arr[200005];
int sparse[400005][25];

int find(int a) {
    ll s = arr[a].first;

    int now = a, ret = 0;
    for (int i = 20; i >= 0; i--) {
        if (arr[sparse[now][i]].second < s + C) {
            now = sparse[now][i];
            ret += (1 << i);
        }
    }

    return ret + 2;
}

void solve() {
    cin >> C >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, a + b};
        arr[i + M] = {a + C, a + b + C};
    }

    sort(arr, arr + 2 * M, [&](pii a, pii b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });

    int right_most = 0, j = 0;
    for (int i = 0; i < 2 * M; i++) {
        while (j < 2 * M) {
            if (arr[j].first > arr[i].second) break;
            if (arr[j].second > arr[right_most].second) right_most = j;
            j++;
        }
        sparse[i][0] = right_most;
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < 2 * M; j++) sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < M; i++) {
        if (arr[i].second >= arr[i].first + C) ans = 1;
        ans = min(ans, find(i));
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