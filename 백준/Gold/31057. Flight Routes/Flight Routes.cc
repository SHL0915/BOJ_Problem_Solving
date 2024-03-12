#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[755][755];
int ans[755][755];

void solve() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            arr[i][j + i + 1] = s[j] - '0';
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (j + i > N) continue;
            int now = 0;
            for (int k = j + 1; k < i + j; k++) now ^= (ans[j][k] * arr[k][j + i]);
            if (now == arr[j][j + i]) continue;
            else {
                cnt++;
                ans[j][j + i] |= 1;
            }
        }
    }
    
    cout << cnt;
    
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