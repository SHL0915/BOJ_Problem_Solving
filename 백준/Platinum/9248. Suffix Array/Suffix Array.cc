#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 500005;

string S;
int N, M, d, sa[SZ], lcp[SZ], temp[SZ], rev[SZ], now[SZ], se[SZ], cnt[SZ];

void solve() {
    cin >> S;
    N = S.length();
    M = max(256, N) + 1;
    for (int i = 0; i < N; i++) sa[i] = i, now[i] = S[i];

    auto cmp = [&](int a, int b) {
        if (now[a] != now[b]) return now[a] < now[b];
        else return now[min(a + d, N)] < now[min(b + d, N)];
    };

    for (d = 1; d < N; d <<= 1) {
        fill(cnt, cnt + M, 0);
        cnt[0] = d;
        for (int i = d; i < N; i++) cnt[now[i]]++;
        for (int i = 1; i < M; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < N; i++) se[--cnt[now[min(i + d, N)]]] = i;

        fill(cnt, cnt + M, 0);
        for (int i = 0; i < N; i++) cnt[now[i]]++;
        for (int i = 1; i < M; i++) cnt[i] += cnt[i - 1];
        for (int i = N - 1; i >= 0; i--) sa[--cnt[now[se[i]]]] = se[i];

        temp[sa[0]] = 1;
        for (int i = 1; i < N; i++) temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < N; i++) now[i] = temp[i];
        if (now[sa[N - 1]] == N) break;
    }

    for (int i = 0; i < N; i++) rev[sa[i]] = i;

    int l = 0;
    for (int i = 0; i < N; i++, l = max(l - 1, 0)) {
        if (rev[i] == 0) continue;
        for (int j = sa[rev[i] - 1]; S[i + l] == S[j + l]; l++);
        lcp[rev[i]] = l;
    }

    for (int i = 0; i < N; i++) cout << sa[i] + 1 << " ";
    cout << "\nx ";
    for (int i = 1; i < N; i++) cout << lcp[i] << " ";
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