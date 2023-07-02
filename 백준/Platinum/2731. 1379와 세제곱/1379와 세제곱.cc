#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

int flag = 0;
string S;
ll pow_10[15];

void BackTracking(int idx, string s);

ll StoI(string s);

string ItoS(ll n, int len);

void solve() {
    cin >> S;
    flag = 0;
    string s = "";
    BackTracking(0, s);
    cout << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    pow_10[0] = 1;
    for (int i = 1; i < 15; i++) pow_10[i] = pow_10[i - 1] * 10;

    cin >> t;
    while (t--) solve();
    return 0;
}

void BackTracking(int idx, string s) {
    if (flag) return;
    if (idx == S.length()) {
        cout << StoI(s);
        flag = 1;
        return;
    }

    for (int i = 0; i < 10; i++) {
        string next = (char) ('0' + i) + s;
        ll Inext = StoI(next);

        __int128 res = Inext;
        res *= Inext;
        res %= pow_10[idx + 1];
        res *= Inext;
        res %= pow_10[idx + 1];

        string convert = ItoS(res, next.length());
        int a = 0;
        for (int i = 0; i <= idx; i++) {
            if (convert[i] != S[S.length() - 1 - idx + i]) a = 1;
        }

        if (a == 0) BackTracking(idx + 1, next);
    }

}

ll StoI(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

string ItoS(ll n, int len) {
    string ret = "";
    while (n) {
        ret = (char) ('0' + n % 10) + ret;
        n /= 10;
    }

    while(ret.length() < len) ret = '0' + ret;

    return ret;
}