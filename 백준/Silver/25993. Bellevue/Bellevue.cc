#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<double, double>;
const double pi = 3.141592653589793238462643383;

int N;
pii arr[50005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    
    double ans = 0;
    for (int i = 1; i < N - 1; i++) {
        double a = arr[i].second / (arr[i].first - arr[0].first);
        double b = arr[i].second / (arr[N - 1].first - arr[i].first);
        
        a = atan(a) / pi * 180;
        b = atan(b) / pi * 180;
        ans = max({ans, a, b});
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
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}