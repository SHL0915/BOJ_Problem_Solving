#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, a, b;

void solve() {
    cin >> N >> a >> b;
    vector<int> ans;
    for (int i = 1; i <= b; i++) ans.push_back(i);
    for (int i = 1; i < a; i++) ans.push_back(ans.back() - 1);
    
    if (ans.size() > N) {
        cout << -1;
        return;
    }
    
    if (ans.back() < 1) {
        int add = 1 - ans.back();
        for (int i = 0; i < a; i++) ans[ans.size() - 1 - i] += add;
    } else if (ans.back() > 1) {
        int sub = ans.back() - 1;
        for (int i = 0; i < a - 1; i++) ans[ans.size() - 1 - i] -= sub;
    }
    reverse(ans.begin(), ans.end());
    cout << ans[0] << " ";
    for(int i = 0; i < N - ans.size(); i++) cout << 1 << " ";
    for(int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
    
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