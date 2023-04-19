#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int G, C, N;
int table[105][20005];

void solve() {
    cin >> G >> C >> N;
    memset(table, -1, sizeof(table));
    int ans = 0;

    table[C][0] = 0;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int a, b; cin >> a >> b;
        for (int j = 0; j <= C; j++) {
            for (int k = 0; k <= 10000; k++) {
                if (table[j][k] == -1) continue;
                if (k >= b) {
                    table[j][k - b] = max(table[j][k - b], 1 + table[j][k]);
                    ans = max(ans, table[j][k - b]);
                }
                if (j && (s[1] != 'e' || k < b)) {
                    int remain = G - b;
                    if (s == "greedy") remain = floor((double)remain / a) * a;
                    else if (s == "honest") remain = round((double)remain / a) * a;
                    else remain = ceil((double)remain / a) * a;
                    table[j - 1][k + remain] = max(table[j - 1][k + remain], 1 + table[j][k]);
                    ans = max(ans, table[j - 1][k + remain]);
                }
            }
        }
    }

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