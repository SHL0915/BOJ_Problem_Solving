#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, ans;
vector<int> tree[5005];
vector<ll> cnt, ccnt[2];

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

    cnt.resize(N + 1);
    ccnt[0].resize(N + 1);
    ccnt[1].resize(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) fill(ccnt[0].begin(), ccnt[0].end(), 0), fill(ccnt[1].begin(), ccnt[1].end(), 0);
        for (int next: tree[i]) {
            fill(cnt.begin(), cnt.end(), 0);
            count(next, i, 1);
            for (int k = 1; k <= N; k++) {
                ans += ccnt[1][k] * cnt[k];
                ccnt[1][k] += ccnt[0][k] * cnt[k];
                ccnt[0][k] += cnt[k];
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