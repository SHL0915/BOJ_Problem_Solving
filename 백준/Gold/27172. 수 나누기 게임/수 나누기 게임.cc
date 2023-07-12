#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
int cnt[1000005];
int ans[1000005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 0; i < N; i++) {
        for (ll j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j) continue;
            if (j * j == arr[i]) {
                if (cnt[j]) {
                    ans[j]++;
                    ans[arr[i]]--;
                }
            } else {
                if (cnt[j]) {
                    ans[j]++;
                    ans[arr[i]]--;
                }
                if (cnt[arr[i] / j]) {
                    ans[arr[i] / j]++;
                    ans[arr[i]]--;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) cout << ans[arr[i]] << " ";
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