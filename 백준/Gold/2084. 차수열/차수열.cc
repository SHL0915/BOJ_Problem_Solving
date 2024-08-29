#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[2005];
int ans[2005][2005];

void solve() {
    cin >> N;
    vector<pii> v;
    for (int i = 1; i <= N; i++) cin >> arr[i], v.push_back({arr[i], i});

    while (1) {
        sort(v.begin(), v.end(), greater<>());
        if (v[0].first == 0) break;

        for (int i = 1; i <= v[0].first; i++) {
            if (v[i].first == 0) {
                cout << -1;
                return;
            }
            ans[v[0].second][v[i].second] = 1;
            ans[v[i].second][v[0].second] = 1;
            v[i].first--;
        }

        v[0].first = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cout << ans[i][j] << " ";
        cout << '\n';
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