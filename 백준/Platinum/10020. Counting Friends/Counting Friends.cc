#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[505];

bool ok(vector<int> &v) {
    while (1) {
        sort(v.begin(), v.end(), greater<>());
        if (v[0] == 0) break;
        if (v[0] >= N) return false;
        for (int i = 1; i <= v[0]; i++) {
            if (v[i] == 0) return false;
            v[i]--;
        }
        v[0] = 0;
    }
    return true;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N + 1; i++) cin >> arr[i];

    vector<int> ans;

    for (int i = 1; i <= N + 1; i++) {
        vector<int> v;
        for (int j = 1; j <= N + 1; j++) {
            if (j != i) v.push_back(arr[j]);
        }

        if (ok(v)) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int i: ans) cout << i << '\n';

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