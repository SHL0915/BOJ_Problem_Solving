#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int cnt[26];
set<int> S[4];

void solve() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) S[i].insert(s[j] - 'A');
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        vector<int> v(4);
        iota(v.begin(), v.end(), 0);

        int flag = 0;
        do {
            int t = 0;
            for (int j = 0; j < s.length(); j++) {
                if (S[v[j]].count(s[j] - 'A') == 0) t = 1;
            }

            if (t == 0) flag = 1;
        } while (next_permutation(v.begin(), v.end()));

        if (flag) cout << "YES\n";
        else cout << "NO\n";

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