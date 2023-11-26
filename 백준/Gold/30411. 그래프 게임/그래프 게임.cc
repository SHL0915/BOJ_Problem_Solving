#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
set<pii> ans;

void solve() {
    cin >> N >> K;
    for (int len = 1; len <= N; len += 2) {
        if (ans.size() == K) break;
        for (int i = 1; i <= N; i++) {
            if (ans.size() == K) break;
            if (i + len > N) break;
            ans.insert({i, i + len});
        }
    }

    if (ans.size() < K) cout << "NO";
    else {
        cout << "YES\n";
        for (pii a: ans) cout << a.first << " " << a.second << '\n';
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