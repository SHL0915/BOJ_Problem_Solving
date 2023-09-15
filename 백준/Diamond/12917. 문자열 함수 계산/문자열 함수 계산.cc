#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int SZ = 100005;

string T;
ll N, M, d, sa[SZ], lcp[SZ], now[SZ], temp[SZ], cnt[SZ], se[SZ], rev[SZ], par[SZ], sz[SZ], mark[SZ];
pii arr[SZ];

int find(int a) {
    if (par[a] == a) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    par[a] = b;
    sz[b] += sz[a];
    return;
}

void solve() {
    cin >> T;
    N = T.length();
    M = max(256LL, N) + 1;
    for (int i = 0; i < N; i++) sa[i] = i, now[i] = T[i];

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
        for (int j = sa[rev[i] - 1]; T[i + l] == T[j + l]; l++);
        lcp[rev[i]] = l;
    }

    for (int i = 1; i <= N; i++) {
        par[i] = i;
        sz[i] = 1;
        arr[i] = {lcp[i - 1], i};
    }
    sort(arr + 1, arr + N + 1, greater<>());

    ll ans = N;

    for (int i = 1; i <= N; i++) {
        ll now = arr[i].first, idx = arr[i].second;
        if (mark[idx - 1] == 1) merge(idx, idx - 1);
        if (mark[idx + 1] == 1) merge(idx, idx + 1);
        mark[idx] = 1;
        ans = max(ans, now * (sz[find(idx)] + 1));
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