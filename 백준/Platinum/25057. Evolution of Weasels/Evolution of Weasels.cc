#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string u, v;

void solve() {
    cin >> u >> v;

    string a = "";
    int bcnt = 0;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == 'B') bcnt++;
        else a += u[i];
        if (a.size() >= 2) {
            string sub = a.substr(a.size() - 2, 2);
            if (sub == "AA" || sub == "CC") {
                for (int k = 0; k < 2; k++) a.pop_back();
            }
        }
    }
    if (bcnt % 2) a += 'B';

    string b = "";
    bcnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 'B') bcnt++;
        else b += v[i];
        if (b.size() >= 2) {
            string sub = b.substr(b.size() - 2, 2);
            if (sub == "AA" || sub == "CC") {
                for (int k = 0; k < 2; k++) b.pop_back();
            }
        }
    }
    if (bcnt % 2) b += 'B';

    if (a == b) cout << "YES\n";
    else cout << "NO\n";

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}