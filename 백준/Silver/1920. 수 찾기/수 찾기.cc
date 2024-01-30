#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
unordered_map<int, int> um;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        um[a] = 1;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        cout << um[a] << '\n';
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