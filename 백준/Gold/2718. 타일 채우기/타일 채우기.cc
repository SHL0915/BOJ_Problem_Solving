#include <bits/stdc++.h>
using namespace std;

int T, N;
int table[1000001];

int DP(int pos);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(table, -1, sizeof(table));
    cin >> T;
    while (T--) {
        cin >> N;
        cout << DP(N) << '\n';
    }
    return 0;
}

int DP(int pos) {
    if (pos < 0) return 0;
    if (pos == 0) return 1;
    int& ret = table[pos];
    if (ret != -1) return ret;
    ret = 0;
    ret += DP(pos - 1);
    ret += 4 * DP(pos - 2);
    for (int i = 4; ; i += 2) {
        if (i > pos) break;
        ret += 3 * DP(pos - i);
    }
    for (int i = 3; ; i += 2) {
        if (i > pos) break;
        ret += 2 * DP(pos - i);
    }
    return ret;
}