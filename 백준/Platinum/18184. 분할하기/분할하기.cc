#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

void solve() {
    cin >> N >> K;

    cout << "YES\n";
    if (K == (1 << N)) {
        for (int i = 0; i < K; i++) cout << i << " ";
    } else {
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if ((1 << i) & K) {
                for (int j = 0; j < 1 << i; j++) ans.push_back((1 << i) + j);
            }
        }
        sort(ans.begin(), ans.end());
        for (int i: ans) cout << i << " ";
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