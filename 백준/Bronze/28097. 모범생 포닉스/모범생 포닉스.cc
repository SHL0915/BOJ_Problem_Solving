#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[125];

void solve() {
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sum += a;
        sum += 8;
    }
    sum -= 8;

    cout << sum / 24 << " " << sum % 24;
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