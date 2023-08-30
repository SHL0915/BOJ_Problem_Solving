#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;

void solve() {
    cin >> N >> S;
    vector<string> v;

    string now = "";
    if (N == 2) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '_') {
                v.push_back(now);
                now = "";
            } else now += tolower(S[i]);
        }
        v.push_back(now);
    } else {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                v.push_back(now);
                now = "";
                now += tolower(S[i]);
            } else now += tolower(S[i]);
        }
        v.push_back(now);
    }

    vector<string> vv;
    for (string a: v) if (a != "") vv.push_back(a);

    string A = "", B = "", C = "";
    for (int i = 0; i < vv.size(); i++) {
        string up = vv[i];
        up[0] += ('A' - 'a');

        if (i == 0) A += vv[i];
        else A += up;
        B += up;

        C += vv[i];
        C += '_';
    }

    C.pop_back();

    cout << A << '\n' << C << '\n' << B;

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