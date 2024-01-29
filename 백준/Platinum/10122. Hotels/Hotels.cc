#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, ans;
vector<int> tree[5005];
ll cnt[5005], ccnt[5005][2];

void count(int node, int par, int lv) {
    cnt[lv]++;
    for (int next: tree[node]) {
        if (next == par) continue;
        count(next, node, lv + 1);
    }
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        memset(ccnt, 0, sizeof(ccnt));
        for (int next: tree[i]) {
            memset(cnt, 0, sizeof(cnt));
            count(next, i, 1);
            for (int k = 1; k <= N; k++) {
                ans += ccnt[k][1] * cnt[k];
                ccnt[k][1] += ccnt[k][0] * cnt[k];
                ccnt[k][0] += cnt[k];
            }
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