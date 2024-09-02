#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M, K, R, W;
vector<pii> edge;
ll arr[1000005];

ll find_r(ll a, ll b, ll k) {
    ll ret = 0;
    
    if (k == 0) return ret;
    
    ll aa = 0, bb = 0, cc = a;
    aa += (a + b) * (k / 2);
    bb += (a + b) * (k / 2);
    
    if (k % 2) aa += a;
    else bb -= b;
    
    ret = max({ret, aa, bb, cc});
    
    return ret;
}

ll find_2r(ll a, ll b, ll k) {
    if (k < R) return find_r(a, b, k);
    ll ret = max(find_r(a, b, R - 1), find_r(b, a, R - 1));
    
    if (R % 2) {
        ll add = (a + b) * (R / 2) + W + a;
        ret = max(ret, add + find_r(b, a, k % R));
    } else {
        ll add = (a + b) * (R / 2) + W;
        ret = max(ret, add + max(find_r(a, b, k % R), find_r(b, a, k % R)));
    }
    
    return ret;
}

ll find(ll a, ll b, ll k) {
    if (k < 2 * R) return find_2r(a, b, k);
    ll ret = find_2r(a, b, 2 * R - 1);
    
    ll add = (a + b) * R + 2 * W;
    ret = max(ret, add * (k / (2 * R)) + max(find_2r(a, b, k % (2 * R)), find_2r(b, a, k % (2 * R))));
    
    if (k / (2 * R)) ret = max(ret, add * (k / (2 * R) - 1) + max(find_2r(a, b, 2 * R - 1), find_2r(b, a, 2 * R - 1)));
    
    return ret;
}

void solve() {
    cin >> N >> M >> K >> R >> W;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edge.emplace_back(u, v);
    }
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    ll ans = 0;
    for (auto &[u, v]: edge) {
        ll a = arr[u], b = arr[v];
        ans = max(ans, find(a, b, K));
        ans = max(ans, find(b, a, K));
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