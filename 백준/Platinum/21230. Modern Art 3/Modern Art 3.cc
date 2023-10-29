#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int A[305];
int table[305][305];

int DP(int left, int right) {
    if (left >= N) return 0;
    if (left == right) return 0;
    int &ret = table[left][right];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = left + 1; i <= right; i++) {
        if (A[i] == A[left]) ret = min(ret, DP(left, i - 1) + DP(i, right));
        else ret = min(ret, 1 + DP(left, i - 1) + DP(i, right));
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    memset(table, -1, sizeof(table));
    cout << 1 + DP(0, N - 1);
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}