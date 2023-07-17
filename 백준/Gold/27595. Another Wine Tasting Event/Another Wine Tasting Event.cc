#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int psum[2000005];

void solve() {
    cin >> N;
    string s;
    cin >> s;
    s = '0' + s;
    for (int i = 1; i < s.length(); i++) {
        psum[i] = psum[i - 1];
        if (s[i] == 'W') psum[i]++;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, psum[i + N - 1] - psum[i - 1]);

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