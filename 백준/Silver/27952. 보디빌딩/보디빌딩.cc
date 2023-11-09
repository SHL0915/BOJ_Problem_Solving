#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, X;
ll A[500005], B[500005];

void solve() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    
    ll now = 0;
    for (int i = 0; i < N; i++) {
        now += B[i];
        if (now < A[i]) {
            cout << -1;
            return;
        }
    }
    
    cout << (now - A[N - 1]) / X;
    
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