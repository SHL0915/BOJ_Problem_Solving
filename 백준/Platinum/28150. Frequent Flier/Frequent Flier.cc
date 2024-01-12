#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
int arr[405005], ans[405005], par[405005];

int find(int a) {
    if (a == par[a]) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) par[a] = b;
    else par[b] = a;
    return;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= 2 * N; i++) par[i] = i;
    int l = 1;
    ll tot = 0;

    for (int i = 1; i <= 2 * N; i++) {
        int r = i;
        if (tot < K) {
            for (; r >= l; r = find(r)) {
                if (arr[r] > K - tot) {
                    arr[r] -= (K - tot);
                    ans[r] += (K - tot);
                    tot = K;
                    break;
                } else {
                    tot += arr[r];
                    ans[r] += arr[r];
                    arr[r] = 0;
                    merge(r, r - 1);
                }
            }
        }

        if (i - l + 1 == M) tot -= ans[l++];
    }

    ll sum = 0;
    for (int i = 1; i <= N; i++) sum += ans[i];

    cout << sum;

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