#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
set<string> s;
map<string, int> m;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        string now = "";
        int flag = 0;
        for (int j = 0; j < S.length(); j++) {
            now += S[j];
            if (s.count(now) == 0 && flag == 0) {
                cout << now << '\n';
                flag = 1;
            }
            s.insert(now);
        }

        m[S]++;
        if (flag) continue;
        if (m[S] == 1) cout << S << '\n';
        else cout << S << m[S] << '\n';
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