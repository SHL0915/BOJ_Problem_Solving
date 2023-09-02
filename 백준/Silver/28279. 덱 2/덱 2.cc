#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
deque<int> dq;

void solve() {
    cin >> N;
    while (N--) {
        int a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            dq.push_front(b);
        } else if (a == 2) {
            cin >> b;
            dq.push_back(b);
        } else if (a == 3) {
            if (dq.size()) {
                int c = dq.front();
                dq.pop_front();
                cout << c << '\n';
            } else cout << -1 << '\n';
        } else if (a == 4) {
            if (dq.size()) {
                int c = dq.back();
                dq.pop_back();
                cout << c << '\n';
            } else cout << -1 << '\n';
        } else if (a == 5) {
            cout << dq.size() << '\n';
        } else if (a == 6) {
            if (dq.size()) cout << "0\n";
            else cout << "1\n";
        } else if (a == 7) {
            if (dq.size() == 0) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        } else {
            if(dq.size() == 0) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
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