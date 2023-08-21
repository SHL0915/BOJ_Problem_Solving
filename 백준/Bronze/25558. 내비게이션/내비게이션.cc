#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
ll Sx, Sy, Ex, Ey;

void solve() {
    cin >> N;
    cin >> Sx >> Sy >> Ex >> Ey;

    ll val = INF, ans = -1;

    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        ll x = Sx, y = Sy, now = 0;
        for (int j = 0; j < M; j++) {
            ll a, b;
            cin >> a >> b;
            now += (abs(a - x) + abs(b - y));
            x = a;
            y = b;
        }
        now += (abs(Ex - x) + abs(Ey - y));
        if (now < val) {
            val = now;
            ans = i;
        }
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