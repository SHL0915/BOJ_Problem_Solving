#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    cin >> N;
    deque<pii> dq;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        dq.push_back({i + 1, a});
    }

    while (dq.size()) {
        pii f = dq.front();
        dq.pop_front();
        cout << f.first << " ";
        if (f.second > 0) {
            f.second--;
            for (int i = 0; i < f.second; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            f.second *= -1;
            for (int i = 0; i < f.second; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
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