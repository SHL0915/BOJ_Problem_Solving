#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
set<char> a, b;

void solve() {
    for (int i = 0; i < 26; i++) {
        char now = ('a' + i);
        if (now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u') a.insert(now);
        else b.insert(now);
    }
    while (1) {
        cin >> S;
        if (S == "end") break;
        
        int flag = 0, fail = 0;
        for (int i = 0; i < S.length(); i++) {
            if (a.count(S[i])) flag = 1;
            if (i > 0) {
                if (S[i] == S[i - 1]) {
                    if (S[i] == 'e' || S[i] == 'o');
                    else fail = 1;
                }
            }
            int cnt1 = 0, cnt2 = 0;
            for (int j = i; j >= max(0, i - 2); j--) {
                if (a.count(S[j])) cnt1++;
                if (b.count(S[j])) cnt2++;
            }
            if (cnt1 == 3 || cnt2 == 3) fail = 1;
        }
        
        if (flag == 0) fail = 1;
        
        if (fail) cout << "<" << S << ">" << " is not acceptable.\n";
        else cout << "<" << S << ">" << " is acceptable.\n";
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