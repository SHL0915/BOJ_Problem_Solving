#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, X;
ll arr[1000005];
ll sqrSum;

void solve() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sqrSum += arr[i] * arr[i];
    }
    
    if(X == 0) {
        for(int i = 1; i <= N; i++) cout << 0 << " ";
        return;
    }
    
    double l = 0, r = 1000000;
    int k = 1000;
    while (k--) {
        double mid = (l + r) / 2;
        double res = sqrSum / (mid * mid * N);
        if (res > X) l = mid;
        else r = mid;
    }
    
    for (int i = 1; i <= N; i++) cout << arr[i] / ((r + l) / 2) << " ";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}