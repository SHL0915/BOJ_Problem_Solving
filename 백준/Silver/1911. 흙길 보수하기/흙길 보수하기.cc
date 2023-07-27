#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, L;
pii arr[10005];

void solve() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N);
    
    int ans = 0, ptr = 0, pos = 0;
    while (ptr < N) {
        if (pos < arr[ptr].first) pos = arr[ptr].first;
        if (pos >= arr[ptr].second) {
            ptr++;
            continue;
        }
        int cnt = (arr[ptr].second - pos - 1) / L + 1;
        ans += cnt;
        pos += cnt * L;
        ptr++;
    }
    
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