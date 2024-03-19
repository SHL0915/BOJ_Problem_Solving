#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string S;
map<string, char> m;

void solve() {
    cin >> S;
    
    m["aespa"] = 'a';
    m["baekjoon"] = 'b';
    m["cau"] = 'c';
    m["debug"] = 'd';
    m["edge"] = 'e';
    m["firefox"] = 'f';
    m["golang"] = 'g';
    m["haegang"] = 'h';
    m["iu"] = 'i';
    m["java"] = 'j';
    m["kotlin"] = 'k';
    m["lol"] = 'l';
    m["mips"] = 'm';
    m["null"] = 'n';
    m["os"] = 'o';
    m["python"] = 'p';
    m["query"] = 'q';
    m["roka"] = 'r';
    m["solvedac"] = 's';
    m["tod"] = 't';
    m["unix"] = 'u';
    m["virus"] = 'v';
    m["whale"] = 'w';
    m["xcode"] = 'x';
    m["yahoo"] = 'y';
    m["zebra"] = 'z';
    
    string now = "", ans = "";
    
    for (int i = 0; i < S.length(); i++) {
        now += S[i];
        if (m.count(now)) {
            ans += m[now];
            now = "";
        }
        if (now.size() > 10) {
            cout << "ERROR!";
            return;
        }
    }
    
    if (now.size() > 0) {
        cout << "ERROR!";
        return;
    }
    
    cout << "It's HG!\n";
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