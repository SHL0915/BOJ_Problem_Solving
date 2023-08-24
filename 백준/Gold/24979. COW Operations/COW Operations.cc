#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int Q;
int C[200005], O[200005], W[200005];

void solve() {
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'C') C[i + 1]++;
        else if (S[i] == 'O') O[i + 1]++;
        else W[i + 1]++;
    }

    for (int i = 1; i <= S.length(); i++) {
        C[i] += C[i - 1];
        O[i] += O[i - 1];
        W[i] += W[i - 1];
    }

    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;

        int c = C[r] - C[l - 1], o = O[r] - O[l - 1], w = W[r] - W[l - 1];
        int sub = min(o, w);
        c += sub;
        o -= sub;
        w -= sub;

        if (o % 2 || w % 2) cout << 'N';
        else if (c % 2 == 0) cout << 'N';
        else cout << 'Y';
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