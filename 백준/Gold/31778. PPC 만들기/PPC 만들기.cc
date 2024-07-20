#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
string S;
priority_queue<int> P, C;

void solve() {
    cin >> N >> K;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'P') P.push(i);
        else C.push(-i);
    }

    for (int i = 0; i < K; i++) {
        if (P.empty() || C.empty()) break;
        int p = P.top(), c = -C.top();
        if (p > c) {
            swap(S[p], S[c]);
            P.pop();
            C.pop();
            P.push(c);
            C.push(-p);
        } else break;
    }

    ll cnt = 0, ans = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'P') cnt++;
        else ans += (cnt * (cnt - 1)) / 2;
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