#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int N, M, d;
int sa[500005], lcp[500005], now[500005], nxt[500005], rev[500005], num[500005], se[500005];

bool cmp(int a, int b) {
    if (now[a] != now[b]) return now[a] < now[b];
    else return now[min(a + d, N)] < now[min(b + d, N)];
}

void solve() {
    cin >> N;
    cin >> S;
    M = max(256, N) + 1;
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        now[i] = S[i];
    }

    for (d = 1; d < N; d <<= 1) {
        fill(num, num + M, 0);
        num[0] = d;
        for (int i = d; i < N; i++) num[now[i]]++;
        for (int i = 1; i < M; i++) num[i] += num[i - 1];
        for (int i = 0; i < N; i++) se[--num[now[min(i + d, N)]]] = i;

        fill(num, num + M, 0);
        for (int i = 0; i < N; i++) num[now[i]]++;
        for (int i = 1; i < M; i++) num[i] += num[i - 1];
        for (int i = N - 1; i >= 0; i--) sa[--num[now[se[i]]]] = se[i];

        nxt[sa[0]] = 1;
        for (int i = 1; i < N; i++) nxt[sa[i]] = nxt[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < N; i++) now[i] = nxt[i];
        if (now[sa[N - 1]] == N) break;
    }

    for (int i = 0; i < N; i++) rev[sa[i]] = i;

    int l = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        l = max(l - 1, 0);
        if (rev[i] == 0) continue;
        for (int j = sa[rev[i] - 1]; S[i + l] == S[j + l]; l++);
        ans = max(ans, l);
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