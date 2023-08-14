#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, Q;
ll arr[2005];
set<int> s[2005];

bool f(int idx, int a, int b) {
    if ((arr[a] - arr[idx]) * (b - idx) <= (arr[b] - arr[idx]) * (a - idx)) return true;
    else return false;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (s[i].size() == 0) s[i].insert(j);
            else {
                if (f(i, *s[i].rbegin(), j)) s[i].insert(j);
            }
        }
    }

    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;

        arr[a] += b;
        for (int i = 1; i < a; i++) {
            auto idx = s[i].lower_bound(a);
            vector<int> v;
            if (*idx == a) {
                idx++;
                while (idx != s[i].end()) {
                    int now = *idx;
                    if (f(i, a, now)) break;
                    else v.push_back(now);
                    idx++;
                }
            } else {
                idx--;
                if (f(i, *idx, a)) {
                    s[i].insert(a);
                    idx++;
                    idx++;
                    while (idx != s[i].end()) {
                        int now = *idx;
                        if (f(i, a, now)) break;
                        else v.push_back(now);
                        idx++;
                    }
                }
            }

            for (int r: v) s[i].erase(r);
        }

        s[a].clear();
        for (int i = a + 1; i <= N; i++) {
            if (s[a].size() == 0) s[a].insert(i);
            else {
                if (f(a, *s[a].rbegin(), i)) s[a].insert(i);
            }
        }

        ll ans = 0;
        for (int i = 1; i <= N; i++) ans += s[i].size();

        cout << ans << '\n';
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