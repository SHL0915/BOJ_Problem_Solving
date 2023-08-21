#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
string arr[305];

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < K; i++) cout << arr[i];
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