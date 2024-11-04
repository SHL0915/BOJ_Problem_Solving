#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

void solve() {
    vector<int> arr[15];

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i].push_back(a), arr[i].push_back(b), arr[i].push_back(c);
        sort(arr[i].begin(), arr[i].end(), greater<>());
    }

    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);

    int ans = 0;
    do {
        ll x = 1e9, y = 1e9;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int idx = v[i];
            int a = arr[idx][0], b = arr[idx][1], c = arr[idx][2];

            if (a <= x && b <= y) {
                x = a, y = b;
                cnt++;
                continue;
            } else if (a <= x && c <= y) {
                x = a, y = c;
                cnt++;
                continue;
            } else if (b <= x && c <= y) {
                x = b, y = c;
                cnt++;
                continue;
            } else break;
        }

        ans = max(ans, cnt);
    } while (next_permutation(v.begin(), v.end()));


    cout << ans << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1, tc = 1;
    //cin >> t;
    while (1) {
        cin >> N;
        if (N == 0) break;
        cout << "Case " << tc++ << ": ";
        solve();
    }
    return 0;
}