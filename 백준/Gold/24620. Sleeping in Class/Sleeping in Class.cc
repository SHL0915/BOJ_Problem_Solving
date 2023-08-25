#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
int psum[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    vector<int> v;
    for (int i = 1; i * i <= psum[N]; i++) {
        if (psum[N] % i) continue;
        if (i * i == psum[N]) v.push_back(i);
        else v.push_back(i), v.push_back(psum[N] / i);
    }

    if (psum[N] == 0) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < v.size(); i++) {
        int flag = 0;
        for (int j = 1; j <= psum[N] / v[i]; j++) {
            int idx = lower_bound(psum, psum + N + 1, v[i] * j) - psum;
            if (psum[idx] != v[i] * j) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) ans = min(ans, N - psum[N] / v[i]);
    }

    cout << ans << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}