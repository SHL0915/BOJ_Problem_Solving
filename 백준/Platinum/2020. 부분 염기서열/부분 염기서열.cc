#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 6643838879;
const ll base = 354;

int N, M, K, ans;
string S, T;
int arr[1005];

void solve() {
    cin >> N >> M >> K;
    cin >> S;
    for (int i = 0; i < S.length(); i++) arr[i] = S[i] - 'A' + 1;

    for (int len = 1; len <= N; len++) {
        ll val = 0, a = 1, ccnt = 0;
        map<ll, int> cnt;

        for (int i = 0; i < len; i++) {
            val = (val * base + arr[i]) % mod;
            a = (a * base) % mod;
        }
        a = mod - a;

        cnt[val]++;
        if (cnt[val] == M) ccnt++;

        for (int j = 1; j <= N - len; j++) {
            val = (val * base + arr[j - 1] * a + arr[j + len - 1]) % mod;

            cnt[val]++;
            if (cnt[val] == M) ccnt++;
        }

        ans += ccnt;
        if (ccnt >= K && K > 0) {
            vector<string> v;
            cnt.clear();
            val = 0;

            for (int i = 0; i < len; i++) val = (val * base + arr[i]) % mod;

            cnt[val]++;

            if (cnt[val] == M) v.push_back(S.substr(0, len));

            for (int j = 1; j <= N - len; j++) {
                val = (val * base + arr[j - 1] * a + arr[j + len - 1]) % mod;
                cnt[val]++;
                if (cnt[val] == M) v.push_back(S.substr(j, len));
            }

            sort(v.begin(), v.end(), [&](string a, string b) {
                if (a.length() == b.length()) return a < b;
                else return a.length() < b.length();
            });

            T = v[K - 1];
            K -= ccnt;
        } else K -= ccnt;
    }

    cout << ans << '\n';
    cout << T;

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