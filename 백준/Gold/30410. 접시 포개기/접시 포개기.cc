#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];

void solve() {
    cin >> N;
    int cnt = 0;
    int pre = 0, now = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 2) {
            if (now == 0) pre++;
            else {
                pre++;
                if (now % 2 == 0) {
                    pre += now / 2;
                    now = 0;
                } else {
                    cnt = max(cnt, pre + now / 2);
                    pre = now / 2 + 1;
                    now = 0;
                }
            }
        } else now++;
    }

    cnt = max(cnt, pre + now / 2);

    if (cnt == 0) {
        cout << 1;
        return;
    }

    ll ans = 2;
    while (cnt > 1) {
        ans *= 2;
        cnt /= 2;
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
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}