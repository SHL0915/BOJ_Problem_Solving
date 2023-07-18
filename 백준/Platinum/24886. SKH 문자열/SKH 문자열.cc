#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, p, q, r;
string S;
set<int> idx;

void solve() {
    cin >> N >> p >> q >> r;
    cin >> S;

    int ans = 0;

    for (int i = 2; i < S.length(); i++) {
        if (S[i] == 'H' && S[i - 1] == 'K' && S[i - 2] == 'S') {
            ans++;
            idx.insert(i - 2);
            idx.insert(i - 1);
            idx.insert(i);
        }
    }

    for (int i = 1; i < S.length(); i++) {
        if (idx.count(i) == 0 && idx.count(i - 1) == 0) {
            string chk = "";
            chk += S[i - 1];
            chk += S[i];

            if (chk == "SK" && r) {
                ans++;
                r--;
                idx.insert(i);
                idx.insert(i - 1);
            }

            if (chk == "SH" && q) {
                ans++;
                q--;
                idx.insert(i);
                idx.insert(i - 1);
            }

            if (chk == "KH" && p) {
                ans++;
                p--;
                idx.insert(i);
                idx.insert(i - 1);
            }
        }
    }

    ll scnt = 0, kcnt = 0, hcnt = 0;

    for (int i = 0; i < S.length(); i++) {
        if (idx.count(i)) continue;
        if (S[i] == 'S') scnt++;
        if (S[i] == 'K') kcnt++;
        if (S[i] == 'H') hcnt++;
    }

    ll add = min({p, q, r});

    for (int i = 1; i <= scnt; i++) {
        if (i > min(q, r)) break;
        ll val = min({kcnt, p, r - i});
        ll val2 = min({hcnt, p - val, q - i});
        add = max(add, i + val + val2 + min({p - val - val2, q - i - val2, r - i - val}));
    }

    for (int i = 1; i <= kcnt; i++) {
        if (i > min(p, r)) break;
        ll val = min({scnt, q, r - i});
        ll val2 = min({hcnt, p - i, q - val});
        add = max(add, i + val + val2 + min({p - i - val2, q - val - val2, r - i - val}));
    }

    for (int i = 1; i <= hcnt; i++) {
        if (i > min(p, q)) break;
        ll val = min({scnt, q - i, r});
        ll val2 = min({kcnt, p - i, r - val});
        add = max(add, i + val + val2 + min({p - i - val2, q - i - val, r - val - val2}));
    }

    cout << ans + add;
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