#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[500005];

void solve() {
    cin >> N;
    for (int i = 0; i < 3 * N; i++) cin >> arr[i];
    sort(arr, arr + 3 * N);
    
    cout << arr[2 * N - 1] - arr[N];
    
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