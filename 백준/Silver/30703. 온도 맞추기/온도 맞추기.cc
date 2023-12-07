#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll A[100005], B[100005], C[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    
    ll ans = 0;
    int a = -1;
    for (int i = 0; i < N; i++) {
        ll d = abs(A[i] - B[i]);
        if (d == 0) {
            if (a == -1) a = 0;
            else {
                if (a == 1) {
                    cout << -1;
                    return;
                }
            }
        } else {
            if (d % C[i]) {
                cout << -1;
                return;
            } else {
                if (a == -1) a = (d / C[i]) % 2, ans = max(ans, d / C[i]);
                else {
                    if (a != (d / C[i]) % 2) {
                        cout << -1;
                        return;
                    } else ans = max(ans, d / C[i]);
                }
            }
        }
    }
    
    cout << ans;
    
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