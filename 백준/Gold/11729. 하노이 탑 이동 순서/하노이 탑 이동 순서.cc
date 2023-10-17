#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void move(int now, int from, int to) {
    if (now < 1) return;
    else {
        int mid = 6 - (from + to);
        move(now - 1, from, mid);
        cout << from << " " << to << '\n';
        move(now - 1, mid, to);
        return;
    }
}

void solve() {
    cin >> N;
    cout << (1LL << N) - 1 << '\n';
    move(N, 1, 3);
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