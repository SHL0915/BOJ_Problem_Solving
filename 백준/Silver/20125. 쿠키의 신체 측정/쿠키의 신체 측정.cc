#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string arr[1005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    pii heart;
    int ans[5] = {0};
    int flag = 0;
    
    for (int i = 0; i < N; i++) {
        if (flag) break;
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '*') {
                heart = {i + 1, j};
                for (int k = j - 1; k >= 0; k--) {
                    if (arr[i + 1][k] == '*') ans[0]++;
                    else break;
                }
                for (int k = j + 1; k < N; k++) {
                    if (arr[i + 1][k] == '*') ans[1]++;
                    else break;
                }
                for (int k = i + 2; k < N; k++) {
                    if (arr[k][j] == '*') ans[2]++;
                    else break;
                }
                for (int k = i + 2 + ans[2]; k < N; k++) {
                    if (arr[k][j - 1] == '*') ans[3]++;
                    else break;
                }
                for (int k = i + 2 + ans[2]; k < N; k++) {
                    if (arr[k][j + 1] == '*') ans[4]++;
                    else break;
                }
                flag = 1;
                break;
            }
        }
    }
    
    cout << heart.first + 1 << " " << heart.second + 1 << '\n';
    for (int i = 0; i < 5; i++) cout << ans[i] << " ";
    
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