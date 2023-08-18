#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int N, d;
int sa[100005], now[100005], nxt[100005];

bool cmp(int a, int b) {
    if (now[a] != now[b]) return now[a] < now[b];
    else return now[min(a + d, N)] < now[min(b + d, N)];
}

void solve() {
    cin >> S;
    N = S.length();
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        now[i] = S[i];
    }

    for (d = 1; d < N; d <<= 1) {
        sort(sa, sa + N, cmp);
        nxt[sa[0]] = 1;
        for (int i = 1; i < N; i++) nxt[sa[i]] = nxt[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < N; i++) now[i] = nxt[i];
        if (now[sa[N - 1]] == N) break;
    }

    for (int i = 0; i < N; i++) cout << sa[i] << '\n';

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