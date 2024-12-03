#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
long double arr[1000005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i], arr[i] /= 1e6;
    
    long double ans = arr[1];
    int l = 1, r = 2;
    
    long double sum = arr[1] / (1 - arr[1]), mul = (1 - arr[1]);
    while (r <= N) {
        mul *= (1 - arr[r]);
        sum += arr[r] / (1 - arr[r]);
        ans = max(ans, mul * sum);
        while (l < r) {
            if ((sum - arr[l] / (1 - arr[l])) >= 1) {
                sum -= arr[l] / (1 - arr[l]);
                mul /= (1 - arr[l]);
                ans = max(ans, sum * mul);
                l++;
            } else break;
        }
        r++;
    }
    
    cout << floor(ans * 1e6);
    
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