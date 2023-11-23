#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
int cnt[4];

void f(int a, int b) {
    int val = min(cnt[a], cnt[b]);
    ans += (a ^ b) * val;
    cnt[a] -= val;
    cnt[b] -= val;
    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    f(3, 0);
    f(2, 1);
    f(3, 1);
    f(2, 0);
    f(3, 2);
    f(1, 0);
    
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