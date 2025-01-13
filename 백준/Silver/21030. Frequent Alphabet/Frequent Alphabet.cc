#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S, T;
int cnt[26];

void solve() {
    cin >> N;
    cin >> S >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            if (S[i] == 'a' + j || T[i] == 'a' + j) cnt[j]++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 26; i++) ans = max(ans, cnt[i]);
    
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