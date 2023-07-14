#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> tree[300005];
int arr[300005];

void dp(int node, int par, int k) {
    arr[node] = 0;
    int cnt = 0;
    for (int next: tree[node]) {
        if (next == par) continue;
        cnt++;
        dp(next, node, k);
        arr[node] += arr[next];
    }

    if (cnt) arr[node] += k - cnt;
    arr[node] = min(arr[node], 0);

    return;
}

int chk(int k) {
    dp(1, 1, k);
    return arr[1] < 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int l = 0, r = N;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (chk(mid) == 0) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
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