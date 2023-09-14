#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
int N, D, ans;
int pi[200005];

int make_pi(int base) {
    ans++;
    pi[base] = 0;
    for (int i = base + 1, j = 0; i < N; i++) {
        while (j && S[i] != S[base + j]) j = pi[j + base - 1];
        if (S[i] == S[base + j]) pi[i] = ++j;
        if (i - base + 1 - pi[i] > D) return i;
    }
    
    return N;
}

void solve() {
    cin >> S;
    cin >> D;
    N = S.length();
    int pos = 0;
    while (pos < N) {
        pos = make_pi(pos);
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