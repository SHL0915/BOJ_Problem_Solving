#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int cnt[10005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < cnt[i]; j++) cout << i << '\n';
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