#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[1000005], pi[1000005];

void make_pi() {
    int pos = 1, k = 0;
    while (pos + k < N) {
        if (arr[pos + k] == arr[k]) {
            k++;
            pi[pos + k - 1] = k;
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

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    reverse(arr, arr + N);
    make_pi();

    pii ans(INF, INF);
    for (int i = 0; i < N; i++) {
        int k = N - 1 - i, p = i + 1 - pi[i];
        if (ans.first + ans.second > k + p) ans = {k, p};
        else if (ans.first == ans.second && ans.second > p) ans = {k, p};
    }

    cout << ans.first << " " << ans.second;
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