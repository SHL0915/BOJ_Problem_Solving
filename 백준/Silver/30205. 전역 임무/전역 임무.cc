#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1000000000LL;

int N, M;
ll P;

void solve() {
    cin >> N >> M >> P;

    for (int i = 0; i < N; i++) {
        vector<ll> v;
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            ll a;
            cin >> a;
            if (a == -1) cnt++;
            else v.push_back(a);
        }
        sort(v.begin(), v.end());
        for (ll a: v) {
            if (a > P) {
                while (cnt) {
                    if (a > P) {
                        P *= 2;
                        cnt--;
                    } else break;
                }
                if (a > P) {
                    cout << 0;
                    return;
                } else P += a;
            } else P += a;
        }
        while (cnt) {
            P *= 2;
            cnt--;
        }
    }

    cout << 1;
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