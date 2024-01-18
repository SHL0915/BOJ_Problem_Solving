#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K;

void solve() {
    cin >> K;
    K++;
    vector<int> ans;
    int now = 1;
    int ptr = 18;

    while (ptr >= 0) {
        if (K >= (1 << ptr)) {
            vector<int> aans;
            if (ans.size() < ptr) {
                for (int i = 0; i < ptr; i++) aans.push_back(now++);
            } else {
                for (int i = 0; i < ptr; i++) aans.push_back(ans[i]);
                aans.push_back(now++);
                for (int i = ptr; i < ans.size(); i++) aans.push_back(ans[i]);
            }
            K -= (1 << ptr);
            swap(ans, aans);
        } else ptr--;
    }

    cout << ans.size() << '\n';
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