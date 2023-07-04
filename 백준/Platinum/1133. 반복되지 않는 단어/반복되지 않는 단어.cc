#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N, A;

void BackTracking(int idx, string s);

int check(string s);

void solve() {
    cin >> K >> N >> A;
    string s = "";
    BackTracking(0, s);
    cout << -1;
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

void BackTracking(int idx, string s) {
    if (check(s)) return;
    if (idx == N) {
        cout << s;
        exit(0);
    }
    for (int i = 0; i < A; i++) {
        BackTracking(idx + 1, s + (char) ('A' + i));
    }
}

int check(string s) {
    int len = s.length();

    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            string cmp = "";
            for(int k = i; k <= j; k++) cmp += s[k];

            int cnt = 1;
            int idx = 0;
            for(int k = j + 1; k < len; k++) {
                if(s[k] == cmp[idx]) idx++;
                else break;
                if(idx == cmp.length()) {
                    cnt++;
                    idx = 0;
                }
            }

            if(cnt >= K) return 1;
        }
    }

    return 0;
}