#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int R, C;
string arr[1005];
int cnt[26], dp[35][1000005], rev[35][1000005], result[2005][2005];

void solve() {
    cin >> R >> C;
    int tot = 0;
    for (int i = 0; i < R; i++) {
        cin >> arr[i];
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == '.') continue;
            else cnt[arr[i][j] - 'a']++, tot++;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= tot; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = 1;
                dp[i][j + cnt[i - 1]] = 1;
                rev[i][j + cnt[i - 1]] = 1;
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= tot; i++) {
        if (!dp[26][i]) continue;
        ans = min(ans, abs(i - (tot - i)));
    }

    int v = (tot - ans) / 2;

    vector<int> even, odd;
    int now = v + ans;

    for (int i = 26; i >= 1; i--) {
        if (rev[i][now]) even.push_back(i - 1), now -= cnt[i - 1];
        else odd.push_back(i - 1);
    }

    vector<pair<int, pii>> sz;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int ecnt = ((R + i) * (C + j)) / 2 + (((R + i) * (C + j)) % 2);
            int ocnt = ((R + i) * (C + j)) / 2;
            if (ecnt >= v + ans && ocnt >= v) sz.push_back({(R + i) * (C + j), {(R + i), (C + j)}});
        }
    }

    sort(sz.begin(), sz.end());
    memset(result, -1, sizeof(result));

    int r = sz[0].second.first, c = sz[0].second.second;
    cout << r << " " << c << '\n';

    int eidx = 0, oidx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((i + j) % 2) {
                while (oidx < odd.size()) {
                    int now = odd[oidx];
                    if (!cnt[now]) oidx++;
                    else break;
                }
                if (oidx >= odd.size()) cout << '.';
                else {
                    cout << (char) ('a' + odd[oidx]);
                    cnt[odd[oidx]]--;
                }
            } else {
                while (eidx < even.size()) {
                    int now = even[eidx];
                    if (!cnt[now]) eidx++;
                    else break;
                }
                if (eidx >= even.size()) cout << '.';
                else {
                    cout << (char) ('a' + even[eidx]);
                    cnt[even[eidx]]--;
                }
            }
        }
        cout << '\n';
    }

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