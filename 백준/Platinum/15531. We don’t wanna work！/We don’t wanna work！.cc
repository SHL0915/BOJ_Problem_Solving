#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
set<pair<pii, string>> A, B;
map<string, pii> m;

void solve() {
    cin >> N;
    int cnt = N;

    for (int i = 0; i < N; i++) {
        string s;
        int a;
        cin >> s >> a;
        B.insert({{a, i}, s});
        m[s] = {a, i};
    }

    for (int i = 0; i < cnt / 5; i++) {
        pair<pii, string> now = *B.rbegin();
        A.insert(now);
        B.erase(now);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int id = N + i;
        char c;
        string s;
        int a;
        cin >> c >> s;
        if (c == '-') {
            pair<pii, string> now = {m[s], s};
            m.erase(s);
            if (A.count(now)) A.erase(now);
            if (B.count(now)) B.erase(now);
            cnt--;
            if (A.size() > cnt / 5) {
                now = *A.begin();
                A.erase(now);
                cout << now.second << " is not working now.\n";
                B.insert(now);
            } else if (A.size() < cnt / 5) {
                now = *B.rbegin();
                B.erase(now);
                cout << now.second << " is working hard now.\n";
                A.insert(now);
            }
        } else {
            cin >> a;
            pair<pii, string> now = {{a, id}, s};
            m[s] = {a, id};
            cnt++;
            if (A.size() < cnt / 5) {
                B.insert(now);
                pair<pii, string> cmp = *B.rbegin();
                B.erase(cmp);
                if (cmp == now) {
                    cout << now.second << " is working hard now.\n";
                    A.insert(cmp);
                } else {
                    cout << now.second << " is not working now.\n";
                    cout << cmp.second << " is working hard now.\n";
                    A.insert(cmp);
                }
            } else {
                A.insert(now);
                pair<pii, string> cmp = *A.begin();
                A.erase(cmp);
                if (cmp == now) {
                    B.insert(cmp);
                    cout << now.second << " is not working now.\n";
                } else {
                    B.insert(cmp);
                    cout << now.second << " is working hard now.\n";
                    cout << cmp.second << " is not working now.\n";
                }
            }
        }
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