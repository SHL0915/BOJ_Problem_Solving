#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
ll arr[105];
vector<int> graph[105];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cin >> K;
    for (int i = 0; i < K; i++) {
        int L, M;
        cin >> L >> M;
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            graph[L].push_back(a);
        }
    }

    ll l = arr[N], r = 1000005;
    ll ans = arr[N];
    while (l <= r) {
        ll mid = (l + r) / 2, flag = 0;

        ll temp[105] = {0};
        temp[N] = mid;
        for (int i = N; i >= 1; i--) {
            int add = max(0LL, temp[i] - arr[i]);
            if (add > 0 && graph[i].size() == 0) flag = 1;
            for (int next: graph[i]) temp[next] += add;
        }

        if (flag) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
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