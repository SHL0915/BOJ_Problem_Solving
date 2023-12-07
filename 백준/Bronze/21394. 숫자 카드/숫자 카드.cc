#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int cnt[10];

void solve() {
    int tot = 0;
    for (int i = 1; i < 10; i++) {
        cin >> cnt[i];
        tot += cnt[i];
    }
    cnt[9] += cnt[6];
    cnt[6] = 0;
    deque<int> ans;
    int a = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            if (a) ans.push_back(i);
            else ans.push_front(i);
            a ^= 1;
        }
    }
    
    if (tot % 2 == 0) reverse(ans.begin(), ans.end());
    
    for (int i: ans) cout << i << " ";
    cout << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}