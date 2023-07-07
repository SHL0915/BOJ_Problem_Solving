#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
vector<int> arr;
int pi[1000005];

void makePi() {
    int pos = 1, k = 0;
    while (pos + k < N) {
        if (arr[pos + k] == arr[k]) {
            k++;
            pi[pos + k - 1] = k;
            ans = max(ans, k);
        } else {
            if (k == 0) pos++;
            else {
                pos += k - pi[k - 1];
                k = pi[k - 1];
            }
        }
    }
    return;
}

int kmp(int K) {
    vector<int> cmp(K);
    for (int i = 0; i < K; i++) cmp[i] = arr[i];

    int ret = 0;

    int n = arr.size(), m = cmp.size(), pos = 0, k = 0;
    while (pos + m <= n) {
        if (k < m && cmp[k] == arr[pos + k]) {
            k++;
            if (k == m) ret++;
        } else {
            if (k == 0) pos++;
            else {
                pos += k - pi[k - 1];
                k = pi[k - 1];
            }
        }
    }

    return ret;
}

void solve() {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    reverse(arr.begin(), arr.end());

    makePi();
    if (ans == 0) cout << -1;
    else cout << ans << " " << kmp(ans) - 1;

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