#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int N;
int sa[500005], now[500005], temp[500005], isa[500005], lcp[500005];
int d;

bool cmp(int p, int q) {
    if (now[p] != now[q]) return now[p] < now[q];
    else return now[min(p + d, N)] < now[min(q + d, N)];
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
        temp[sa[0]] = 1;
        for (int i = 1; i < N; i++) temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < N; i++) now[i] = temp[i];
        if (now[sa[N - 1]] == N) break;
    }

    for(int i = 0; i < N; i++) isa[sa[i]] = i;

    int l = 0;
    for(int i = 0; i < N; i++, l = max(l - 1, 0)) {
        if(isa[i] == 0) continue;
        for(int j = sa[isa[i] - 1]; S[i + l] == S[j + l]; l++);
        lcp[isa[i]] = l;
    }

    for (int i = 0; i < N; i++) cout << sa[i] + 1 << " ";
    cout << endl << "x ";
    for(int i = 1; i < N; i++) cout << lcp[i] << " ";

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