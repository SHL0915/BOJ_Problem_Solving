#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M;

void solve() {
    cin >> N >> M;
    set<ll> cand;
    cand.insert(N);
    while (1) {
        if (*(cand.rbegin()) < M) break;
        set<ll> next;
        for (ll i: cand) {
            if (i == M) {
                cout << "YES";
                return;
            }
            if (i % 2) {
                next.insert(i / 2);
                next.insert(i / 2 + 1);
            } else next.insert(i / 2);
        }
        swap(next, cand);
    }
    cout << "NO";
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