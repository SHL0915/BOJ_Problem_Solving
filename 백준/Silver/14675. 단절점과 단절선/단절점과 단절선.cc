#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int degree[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            if (degree[b] == 1) cout << "no\n";
            else cout << "yes\n";
        } else cout << "yes\n";
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