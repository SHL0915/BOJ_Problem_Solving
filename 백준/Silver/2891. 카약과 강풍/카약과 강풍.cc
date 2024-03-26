#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, R;
int cnt[15];

void solve() {
    cin >> N >> S >> R;
    for (int i = 1; i <= N; i++) cnt[i] = 1;
    for (int i = 0; i < S; i++) {
        int a;
        cin >> a;
        cnt[a]--;
    }
    for (int i = 0; i < R; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 1) ans++;
        else if (cnt[i] == 2) {
            if (i > 1 && cnt[i - 1] == 0) {
                ans += 2;
                cnt[i - 1]++;
                cnt[i]--;
            } else if (i < N && cnt[i + 1] == 0) {
                ans++;
                cnt[i + 1]++;
                cnt[i]--;
            } else ans++;
        }
    }
    
    cout << N - ans;
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