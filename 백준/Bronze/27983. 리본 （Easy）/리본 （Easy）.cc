#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1005];
int L[1005];
char color[1005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) cin >> L[i];
    for (int i = 1; i <= N; i++) cin >> color[i];
    
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (color[i] == color[j]) continue;
            if (arr[j] - arr[i] <= L[i] + L[j]) {
                cout << "YES\n";
                cout << i << " " << j;
                return;
            }
        }
    }
    
    cout << "NO\n";
    
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