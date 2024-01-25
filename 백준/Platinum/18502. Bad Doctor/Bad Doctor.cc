#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 500005;

int N, M;
ll arr[500005];
vector<pii> add[1000005];
vector<pii> del[1000005];
set<int> S[500005];
ll ans[500005];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            add[l].push_back({a, i});
            del[r + 1].push_back({a, i});
        }
    }

    int days = 1000001;

    for (int i = 1; i <= days; i++) {
        ll len = (days - i + 1);

        for (pii a: add[i]) {
            int med = a.first, idx = a.second;
            if (S[med].size() == 0) {
                ans[1] += arr[med] * len;
                ans[idx] -= arr[med] * len;
                ans[idx + 1] += arr[med] * len;
            } else if (S[med].size() == 1) {
                ans[*S[med].begin()] += arr[med] * len;
                ans[*S[med].begin() + 1] -= arr[med] * len;
            }
            S[med].insert(idx);
        }
        for (pii a: del[i]) {
            int med = a.first, idx = a.second;
            if (S[med].size() == 2) {
                S[med].erase(idx);
                ans[*S[med].begin()] -= arr[med] * len;
                ans[*S[med].begin() + 1] += arr[med] * len;
            } else if (S[med].size() == 1) {
                ans[1] -= arr[med] * len;
                ans[*S[med].begin()] += arr[med] * len;
                ans[*S[med].begin() + 1] -= arr[med] * len;
                S[med].erase(idx);
            } else S[med].erase(idx);
        }
    }

    for (int i = 1; i <= N; i++) ans[i] += ans[i - 1];

    for (int i = 1; i <= N; i++) cout << ans[i] << " ";

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