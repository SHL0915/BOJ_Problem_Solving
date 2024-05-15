#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
deque<int> dq;

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) dq.push_back(i);
    
    while (dq.size()) {
        cout << dq.front() << ' ';
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
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