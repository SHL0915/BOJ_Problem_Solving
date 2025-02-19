#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[4005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    set<int> ans;
    for (int i = 1; i < N; i++) ans.insert(arr[i] - arr[0]);
    
    for (int i = 1; i < N; i++) {
        set<int> s;
        for (int j = 0; j < N; j++) s.insert(abs(arr[j] - arr[i]));
        vector<int> del;
        for (int a: ans) if (!s.count(a)) del.push_back(a);
        for (int a: del) ans.erase(a);
    }
    
    cout << ans.size() << '\n';
    for (int i: ans) cout << i << " ";
    
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