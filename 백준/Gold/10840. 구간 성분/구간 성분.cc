#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 6643838879;
const ll base = 61900;

int N, M;
string A, B;

void solve() {
    cin >> A >> B;
    if (A.length() > B.length()) swap(A, B);
    N = A.length();
    M = B.length();
    int ans = 0;

    for(int len = N; len >= 1; len--) {
        set<ll> s;
        int cnt[26] = {0};
        int flag = 0;

        ll val = 0;
        for (int i = 0; i < len; i++) cnt[A[i] - 'a']++;

        for (int i = 0; i < 26; i++) val = (val * base + cnt[i]) % mod;
        s.insert(val);

        for (int i = 1; i <= N - len; i++) {
            cnt[A[i - 1] - 'a']--;
            cnt[A[i + len - 1] - 'a']++;

            val = 0;
            for (int j = 0; j < 26; j++) val = (val * base + cnt[j]) % mod;
            s.insert(val);
        }

        memset(cnt, 0, sizeof(cnt));
        val = 0;
        for (int i = 0; i < len; i++) cnt[B[i] - 'a']++;

        for (int i = 0; i < 26; i++) val = (val * base + cnt[i]) % mod;
        if (s.count(val)) flag = 1;

        for (int i = 1; i <= M - len; i++) {
            cnt[B[i - 1] - 'a']--;
            cnt[B[i + len - 1] - 'a']++;

            val = 0;
            for (int j = 0; j < 26; j++) val = (val * base + cnt[j]) % mod;
            if (s.count(val)) flag = 1;
        }

        if (flag) {
            cout << len;
            return;
        }
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