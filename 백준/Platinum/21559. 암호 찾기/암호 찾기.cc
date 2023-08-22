#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 6643838879;
const ll base = 555;

int N, K;
string A, B;

void solve() {
    cin >> N >> K;
    cin >> A >> B;

    set<ll> S, ans;

    ll M = 1, hash = 0;
    for (int i = 0; i < K; i++) {
        hash = ((hash * base) % mod + (A[i] - '0')) % mod;
        M = (M * base) % mod;
    }
    M = mod - M;

    S.insert(hash);
    for (int i = 1; i <= A.length() - K; i++) {
        hash = (hash * base + (A[i - 1] - '0') * M + (A[i + K - 1] - '0')) % mod;
        S.insert(hash);
    }

    hash = 0;
    for (int i = 0; i < K; i++) hash = (hash * base + (B[i] - '0')) % mod;
    if (S.count(hash)) ans.insert(hash);
    for (int i = 1; i <= B.length() - K; i++) {
        hash = (hash * base + (B[i - 1] - '0') * M + (B[i + K - 1] - '0')) % mod;
        if (S.count(hash)) ans.insert(hash);
    }

    cout << ans.size();
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