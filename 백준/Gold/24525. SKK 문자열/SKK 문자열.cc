#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int Scnt[100005], Kcnt[100005], psum[100005];
map<int, int> idx;

void solve() {
    cin >> S;
    for (int i = 1; i <= S.length(); i++) {
        char now = S[i - 1];
        if (now == 'S') Scnt[i]++, psum[i] -= 2;
        else if (now == 'K') Kcnt[i]++, psum[i]++;
        Scnt[i] += Scnt[i - 1];
        Kcnt[i] += Kcnt[i - 1];
        psum[i] += psum[i - 1];
        idx[psum[i]] = i;
    }

    int ans = 0;

    for (int i = 1; i <= S.length(); i++) {
        if (idx[psum[i - 1]] != 0) {
            int nxt = idx[psum[i - 1]];
            if (Scnt[nxt] - Scnt[i - 1] == 0) continue;
            int len = nxt - i + 1;
            ans = max(ans, len);
        }
    }

    if (!ans) cout << -1;
    else cout << ans;

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