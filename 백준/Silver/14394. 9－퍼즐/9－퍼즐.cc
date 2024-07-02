#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string A, B;
int cnt[26][2];

void solve() {
    cin >> A >> B;
    
    for (int i = 0; i < A.length(); i++) {
        if (A[i] == '*') continue;
        cnt[A[i] - 'A'][0]++;
    }
    for (int i = 0; i < B.length(); i++) {
        if (B[i] == '*') continue;
        cnt[B[i] - 'A'][1]++;
    }
    
    int ans = 9;
    ans -= min(cnt['R' - 'A'][0], cnt['R' - 'A'][1]);
    ans -= min(cnt['G' - 'A'][0], cnt['G' - 'A'][1]);
    ans -= min(cnt['B' - 'A'][0], cnt['B' - 'A'][1]);
    ans -= min(cnt['Y' - 'A'][0], cnt['Y' - 'A'][1]);
    
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