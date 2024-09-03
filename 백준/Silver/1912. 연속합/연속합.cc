#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
ll psum[100005];

ll dnc(int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    
    ll ret = max(dnc(l, m), dnc(m + 1, r));
    
    ll lmax = 0, rmax = 0;
    for (int i = m - 1; i >= l; i--) lmax = max(lmax, psum[m - 1] - psum[i - 1]);
    for (int i = m + 1; i <= r; i++) rmax = max(rmax, psum[i] - psum[m]);
    
    ret = max(ret, arr[m] + lmax + rmax);
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + arr[i];
    
    cout << dnc(1, N);
    
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