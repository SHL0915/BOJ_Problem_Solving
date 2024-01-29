#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<pii> ans;

void f(int n, int from, int to, int use) {
    if (n == 1) {
        ans.push_back({from, to});
        return;
    } else {
        f(n - 1, from, use, to);
        ans.push_back({from, to});
        f(n - 1, use, to, from);
        return;
    }
}

void g(int n, int now) {
    if (n == 1) ans.push_back({now, 3});
    else if (n == 2) {
        ans.push_back({now, (now + 1) % 3});
        ans.push_back({now, 3});
        ans.push_back({(now + 1) % 3, 3});
    } else {
        f(n - 2, now, (now + 2) % 3, (now + 1) % 3);
        g(2, now);
        g(n - 2, (now + 2) % 3);
    }
    return;
}

void solve() {
    cin >> N;
    g(N, 0);

    cout << ans.size() << '\n';
    for (pii a: ans) cout << (char) ('A' + a.first) << " " << (char) ('A' + a.second) << '\n';

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