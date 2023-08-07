#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

string S;

pii f(int idx) {
    pii ret = {0, 0};
    if (idx == S.length()) return ret;
    ll base = 1 << idx;
    if (S[idx] == '0');
    else if (S[idx] == '1') ret.first += base;
    else if (S[idx] == '2') ret.second += base;
    else {
        ret.first += base;
        ret.second += base;
    }

    pii nxt = f(idx + 1);
    ret.first += nxt.first;
    ret.second += nxt.second;

    return ret;
}

void solve() {
    cin >> S;
    cout << S.length() << " ";

    reverse(S.begin(), S.end());
    pii ans = f(0);

    cout << ans.first << " " << ans.second;
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