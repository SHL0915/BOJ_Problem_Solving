#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll T;
int N, M;
int A[1005], B[1005];
ll pA[1005], pB[1005];
map<ll, int> m;

void solve() {
    cin >> T;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i], pA[i] = pA[i - 1] + A[i];

    cin >> M;
    for (int i = 1; i <= M; i++) cin >> B[i], pB[i] = pB[i - 1] + B[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) m[pA[j] - pA[i - 1]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j++) ans += m[T - (pB[j] - pB[i - 1])];
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