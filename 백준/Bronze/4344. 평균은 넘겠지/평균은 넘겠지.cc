#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1005];

void solve() {
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] * N > sum) cnt++;
    }
    
    double ans = 100000 * (double) (cnt) / N;
    ans = round(ans);
    
    cout << ans / 1000 << "%\n";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(3);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}