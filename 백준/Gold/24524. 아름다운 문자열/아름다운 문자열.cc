#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S, T;
int pos[26];
int cnt[30];

void solve() {
    cin >> S >> T;
    for (int i = 0; i < 26; i++) pos[i] = 29;
    for (int i = 0; i < T.length(); i++) pos[T[i] - 'a'] = i;

    for (int i = 0; i < S.length(); i++) {
        int idx = pos[S[i] - 'a'];
        cnt[idx]++;
        if (idx) {
            cnt[idx] = min(cnt[idx], cnt[idx - 1]);
        }
    }

    cout << cnt[T.length() - 1];

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