#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
vector<pair<pii, ll>> apple, cow;
multiset<pii> s;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll q, t, x, n;
        cin >> q >> t >> x >> n;
        if (q == 2) apple.push_back({{t - x, t + x}, n});
        else cow.push_back({{t - x, t + x}, n});
    }

    sort(apple.begin(), apple.end());
    sort(cow.begin(), cow.end());

    ll ans = 0, cow_idx = 0;
    for (int i = 0; i < apple.size(); i++) {
        ll u = apple[i].first.first, v = apple[i].first.second, n = apple[i].second;
        while (cow_idx < cow.size()) {
            if (cow[cow_idx].first.first <= u) {
                s.insert({cow[cow_idx].first.second, cow[cow_idx].second});
                cow_idx++;
            } else break;
        }

        pii find = {v, INF};
        auto idx = s.upper_bound(find);
        if (idx != s.begin()) {
            idx--;
            vector<pii> del, ins;
            while (n) {
                ll add = min(n, idx->second);
                ans += add;

                if (add == idx->second) del.push_back(*idx);
                else {
                    del.push_back(*idx);
                    ins.push_back({idx->first, idx->second - add});
                    break;
                }

                n -= add;
                if (idx == s.begin()) break;
                idx--;
            }

            for (pii e: del) s.erase(s.find(e));
            for (pii e: ins) s.insert(e);
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