#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string arr[105];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;

    for (int i = 0; i < M; i++) {
        vector<int> cnt(26, 0);
        for (int j = 0; j < N; j++) cnt[arr[j][i] - 'a']++;
        ans += (N - *max_element(cnt.begin(), cnt.end()));
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