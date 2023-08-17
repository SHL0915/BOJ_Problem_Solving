#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod1 = 6643838879;
const ll mod2 = 2147483647;
const ll base = 205;

int L;
string S;
int arr[2000005];

void solve() {
    cin >> L >> S;
    for (int i = 0; i < S.length(); i++) arr[i] = S[i] - 'a' + 1;

    int l = 1, r = L;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        unordered_map<ll, ll> um;

        ll val1 = 0, val2 = 0, a = 1, b = 1;
        for (int i = 0; i < mid; i++) {
            val1 = ((val1 * base) % mod1 + arr[i]) % mod1;
            val2 = ((val2 * base) % mod2 + arr[i]) % mod2;
            a = (a * base) % mod1;
            b = (b * base) % mod2;
        }
        a = (mod1 - a);
        b = (mod2 - b);

        int flag = 0;

        um[val1] = val2;
        for (int i = 1; i <= L - mid; i++) {
            val1 = (val1 * base + arr[i - 1] * a + arr[i + mid - 1]) % mod1;
            val2 = (val2 * base + arr[i - 1] * b + arr[i + mid - 1]) % mod2;
            if (um[val1] == val2) {
                flag = 1;
                break;
            } else um[val1] = val2;
        }

        if (flag) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
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