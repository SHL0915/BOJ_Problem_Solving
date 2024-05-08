#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, P;
pii arr[10005];

void solve() {
    cin >> N >> P;
    for (int i = 0; i < P; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;
    }

    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < P; j++) {
            arr[j].first++, arr[j].first %= N;
            arr[j].second++, arr[j].second %= N;
            if (arr[j].first > arr[j].second) swap(arr[j].first, arr[j].second);
        }
        sort(arr, arr + P);
        int cnt = 0, last = 0;
        for (int j = 0; j < P; j++) {
            last = max(last, arr[j].first);
            cnt += max(0, arr[j].second - last);
            last = max(arr[j].second, last);
        }
        ans = min(ans, cnt);
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