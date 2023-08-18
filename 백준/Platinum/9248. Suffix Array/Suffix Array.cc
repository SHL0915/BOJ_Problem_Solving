#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int N, d;
int suffix[500005], lcp[5000005], group[500005], temp[500005], rev[500005];

bool cmp(int a, int b) {
    if (group[a] != group[b]) return group[a] < group[b];
    return group[min(a + d, N)] < group[min(b + d, N)];
}

void solve() {
    cin >> S;
    N = S.length();
    for (int i = 0; i < N; i++) {
        suffix[i] = i;
        group[i] = S[i];
    }

    for (d = 1; d < N; d <<= 1) {
        sort(suffix, suffix + N, cmp);
        temp[suffix[0]] = 1;
        for (int i = 1; i < N; i++) temp[suffix[i]] = temp[suffix[i - 1]] + cmp(suffix[i - 1], suffix[i]);
        for (int i = 0; i < N; i++) group[i] = temp[i];
        if (group[suffix[N - 1]] == N) break;
    }

    for (int i = 0; i < N; i++) rev[suffix[i]] = i;

    int l = 0;
    for (int i = 0; i < N; i++) {
        l = max(l - 1, 0);
        if (rev[i] == 0) continue;
        for (int j = suffix[rev[i] - 1]; S[i + l] == S[j + l]; l++);
        lcp[rev[i]] = l;
    }

    for (int i = 0; i < N; i++) cout << suffix[i] + 1 << " ";
    cout << '\n' << "x ";
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