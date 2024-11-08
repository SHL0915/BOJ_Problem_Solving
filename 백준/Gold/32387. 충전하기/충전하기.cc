#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, Q;
set<int> s;
int arr[1000005];

void solve() {
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) s.insert(i);
    
    int now = 0;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        now++;
        if (a == 1) {
            auto it = s.lower_bound(b);
            if (it == s.end()) cout << -1 << '\n';
            else {
                cout << *it << '\n';
                arr[*it] = now;
                s.erase(it);
            }
        } else {
            auto it = s.lower_bound(b);
            if (it == s.end() || *it != b) {
                cout << arr[b] << '\n';
                s.insert(b);
            } else cout << -1 << '\n';
        }
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