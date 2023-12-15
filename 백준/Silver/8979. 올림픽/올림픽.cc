#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
pair<pii, pii> arr[1005];

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = {{b, c},
                  {d, a}};
    }
    sort(arr, arr + N, greater<>());
    
    for (int i = 0; i < N; i++) {
        if (arr[i].second.second == K) {
            int ans = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j].first.first != arr[i].first.first || arr[j].first.second != arr[i].first.second ||
                    arr[j].second.first != arr[i].second.first) {
                    ans = j;
                    break;
                }
            }
            cout << ans + 2;
            break;
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