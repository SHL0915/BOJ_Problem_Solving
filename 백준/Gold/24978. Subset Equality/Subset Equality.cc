#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S, T;
int Q;
int adj[18][18];
int chk[18];

void solve() {
    cin >> S >> T;

    for (int i = 0; i < 18; i++) {
        for (int j = i + 1; j < 18; j++) {
            string a = "", b = "";
            for (auto k: S) {
                if (k - 'a' == i || k - 'a' == j) a += k;
            }
            for (auto k: T) {
                if (k - 'a' == i || k - 'a' == j) b += k;
            }

            if (a == b) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < 18; i++) {
        string a = "", b = "";
        for (auto k: S) {
            if (k - 'a' == i) a += k;
        }
        for (auto k: T) {
            if (k - 'a' == i) b += k;
        }

        if (a == b) chk[i] = 1;
    }

    cin >> Q;
    while (Q--) {
        string a;
        cin >> a;
        int flag = 0;
        for (int i = 0; i < a.length(); i++) {
            if (chk[a[i] - 'a'] == 0) flag = 1;
            for (int j = i + 1; j < a.length(); j++) {
                if (adj[a[i] - 'a'][a[j] - 'a'] == 0) flag = 1;
            }
        }

        if (flag) cout << "N";
        else cout << "Y";
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