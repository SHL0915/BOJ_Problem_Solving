#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];

void solve() {
    cin >> N;
    int cnt = 0;
    int one = 0, two = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 2) {
            if (one) {
                if (one % 2) {
                    cnt = max(cnt, two + one / 2);
                    two = one / 2 + 1;
                    one = 0;
                } else two += one / 2 + 1, one = 0;
            } else two++;
        } else one++;
    }
    cnt = max(cnt, two + one / 2);

    ll ans = 1;
    while (cnt) ans *= 2, cnt /= 2;

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