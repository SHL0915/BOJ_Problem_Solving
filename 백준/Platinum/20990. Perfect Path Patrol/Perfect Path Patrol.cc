#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
ll ans;
vector<pii> tree[500005];

void DFS(int node, int par, ll val) {
    ll tot = val;
    vector<ll> v;
    v.push_back(val);
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        if (next == par) continue;
        ll nval = tree[node][i].second;
        tot += nval;
        v.push_back({nval});
        DFS(next, node, nval);
    }

    sort(v.begin(), v.end(), greater<>());

    if (v.size() == 0) return;
    if (v[0] >= tot - v[0]) ans += v[0] - val;
    else ans += (tot + 1) / 2 - val;

    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    DFS(1, 1, 0);
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