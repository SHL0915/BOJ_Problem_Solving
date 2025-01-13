#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[20005];

void solve() {
    cin >> N;
    
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] % 2) a++;
        else b++;
    }
    
    int ans = min(a, b);
    a -= ans, b -= ans;
    ans += a / 2;
    
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