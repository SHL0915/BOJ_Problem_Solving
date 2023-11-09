#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[35], A[15];

void solve() {
    cin >> N >> M;
    vector<int> B[15];
    
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            B[i].push_back(a);
        }
        cin >> A[i];
    }
    
    for (int i = 1; i <= M; i++) cin >> arr[i];
    
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int m = 105;
        for (int a: B[i]) m = min(m, arr[a]);
        ans += A[i] * m;
    }
    
    cout << ans << '\n';
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}