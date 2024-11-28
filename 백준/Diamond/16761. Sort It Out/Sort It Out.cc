#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int sz = 1e6 + 5;
const ll inf = 1e18 + 5;

ll N, K;
int arr[sz], idx[sz], ok[sz];
pii seg[2 * sz];
vector<pii> lis[sz];

pii merge(pii a, pii b) {
    pii ret = {0, 0};
    ret.first = max(a.first, b.first);
    if (ret.first == a.first) ret.second += a.second;
    if (ret.first == b.first) ret.second += b.second;
    ret.second = min(ret.second, inf);
    return ret;
}

void update(int pos, pii v) {
    for (seg[pos += sz] = v; pos > 0; pos >>= 1) seg[pos >> 1] = merge(seg[pos], seg[pos ^ 1]);
}

pii query(int l, int r) {
    r++;
    pii ret = {0, 0};
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = merge(ret, seg[l++]);
        if (r & 1) ret = merge(ret, seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) cin >> arr[i], idx[arr[i]] = i;
    update(N + 1, {0, 1});
    
    ll ans = 0;
    
    for (int i = N; i >= 1; i--) {
        pii now = query(arr[i], N + 1);
        now.first++;
        ans = max(ans, now.first);
        lis[now.first].push_back({arr[i], now.second});
        update(arr[i], now);
    }
    
    ll now = 0;
    
    for (int i = ans; i >= 1; i--) {
        sort(lis[i].begin(), lis[i].end(), greater<>());
        for (auto j: lis[i]) {
            ll v = j.first, cnt = j.second;
            if (v <= now || idx[v] <= idx[now]) continue;
            if (K > cnt) K -= cnt;
            else {
                now = v;
                ok[now] = 1;
                break;
            }
        }
    }
    
    vector<int> ans_v;
    for (int i = 1; i <= N; i++) if (!ok[i]) ans_v.push_back(i);
    
    cout << ans_v.size() << '\n';
    for (int i: ans_v) cout << i << '\n';
    
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