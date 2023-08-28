#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii arr[45], A[25], B[25], E;
ll ans[45];
vector<pii> v[25];

void solve() {
    cin >> N >> E.first >> E.second;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < N / 2; i++) A[i] = arr[i];
    for (int i = N / 2; i < N; i++) B[i - N / 2] = arr[i];

    int sz_a = N / 2, sz_b = N - N / 2;

    for (int i = 0; i < (1 << sz_a); i++) {
        ll x = 0, y = 0, cnt = 0;
        for (int j = 0; j < sz_a; j++) {
            if (i & (1 << j)) {
                x += A[j].first;
                y += A[j].second;
                cnt++;
            }
        }

        v[cnt].push_back({x, y});
    }

    for (int i = 0; i <= sz_a; i++) sort(v[i].begin(), v[i].end());

    for (int i = 0; i < (1 << sz_b); i++) {
        ll x = 0, y = 0, cnt = 0;
        for (int j = 0; j < sz_b; j++) {
            if (i & (1 << j)) {
                x += B[j].first;
                y += B[j].second;
                cnt++;
            }
        }

        ll nx = E.first - x, ny = E.second - y;
        pii find = {nx, ny};

        for (int j = 0; j <= sz_a; j++) {
            int idx = lower_bound(v[j].begin(), v[j].end(), find) - v[j].begin();
            if (idx == v[j].size() || v[j][idx] != find) continue;
            else {
                int uidx = upper_bound(v[j].begin(), v[j].end(), find) - v[j].begin();
                ans[cnt + j] += uidx - idx;
            }
        }
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';

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