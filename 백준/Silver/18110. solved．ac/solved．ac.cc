#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[300005];

void solve() {
    cin >> N;
    double a = (double) (N) * 0.15;
    a += 0.5;
    int b = a;

    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    ll sum = 0, cnt = 0;
    for (int i = b; i < N - b; i++) {
        sum += arr[i];
        cnt++;
    }

    if (cnt == 0) cout << 0;
    else {
        double ans = double(sum) / cnt;

        ans += 0.5;
        cout << (int) ans;
    }
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