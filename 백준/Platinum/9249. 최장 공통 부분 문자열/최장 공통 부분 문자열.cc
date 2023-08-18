#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B, S;
int N, d;
int sa[200005], lcp[200005], now[200005], nxt[200005], rev[200005];

bool cmp(int a, int b) {
    if (now[a] != now[b]) return now[a] < now[b];
    else return now[min(a + d, N)] < now[min(b + d, N)];
}

void solve() {
    cin >> A >> B;
    S = A;
    S += '.';
    S += B;
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

    for (int i = 0; i < N; i++) rev[sa[i]] = i;

    int l = 0;
    for (int i = 0; i < N; i++) {
        l = max(l - 1, 0);
        if (rev[i] == 0) continue;
        for (int j = sa[rev[i] - 1]; S[i + l] == S[j + l]; l++);
        lcp[rev[i]] = l;
    }

    int ans = 0, idx = -1;
    for (int i = 1; i < N; i++) {
        if ((sa[i - 1] < A.length() && sa[i] > A.length()) || (sa[i - 1] > A.length() && sa[i] < A.length())) {
            if (ans < lcp[i]) {
                ans = lcp[i];
                idx = sa[i];
            }
        }
    }

    cout << ans << '\n';
    if (ans) {
        for (int i = idx; i < idx + ans; i++) cout << S[i];
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