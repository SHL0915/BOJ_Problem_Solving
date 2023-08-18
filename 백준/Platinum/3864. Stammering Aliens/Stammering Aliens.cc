#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int M, N, d;
string S;
int sa[40005], lcp[40005], now[40005], nxt[40005], rev[40005];

bool cmp(int a, int b) {
    if (now[a] != now[b]) return now[a] < now[b];
    else return now[min(a + d, N)] < now[min(b + d, N)];
}

void solve() {
    N = S.length();
    now[N] = 0;

    if (M == 1) {
        cout << N << " " << 0 << '\n';
        return;
    }

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

    for (int i = 0; i < N; i++) rev[sa[i]] = i;

    int l = 0;
    for (int i = 0; i < N; i++) {
        l = max(l - 1, 0);
        if (rev[i] == 0) continue;
        for (int j = sa[rev[i] - 1]; S[i + l] == S[j + l]; l++);
        lcp[rev[i]] = l;
    }

    int lo = 1, hi = N;
    int ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int flag = 0, cnt = 0;
        for (int i = 1; i < N; i++) {
            if (lcp[i] >= mid) cnt++;
            else cnt = 0;
            if (cnt >= M - 1) flag = 1;
        }

        if (flag) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    if (ans == 0) cout << "none\n";
    else {
        int cnt = 0;
        int ii = sa[0], ix = -1;
        for (int i = 1; i < N; i++) {
            if (lcp[i] >= ans) cnt++, ii = max(ii, sa[i]);
            else cnt = 0, ii = sa[i];
            if (cnt >= M - 1) ix = max(ix, ii);
        }
        cout << ans << " " << ix << '\n';
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
    while (1) {
        cin >> M;
        if (M == 0) break;
        cin >> S;
        solve();
    }
    return 0;
}