#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;

void solve() {
    cin >> N >> S;

    int cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'I') cnt++;
    }

    int l = 0, r = cnt, ok = -1;
    while (l <= r) {
        int m = (l + r) / 2;

        int a = m, b = 0, c = 0;

        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] == 'J') {
                if (c) c--;
                else continue;
            } else if (S[i] == 'O') {
                if (b) b--, c++;
                else continue;
            } else {
                if (a) a--, b++;
                else {
                    if (c) c--;
                }
            }
        }

        if (!a && !b && !c) {
            ok = m;
            l = m + 1;
        } else r = m - 1;
    }

    cout << ok;

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