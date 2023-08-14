#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, L;
vector<pii> tree[200005];
set<pii> s[200005];
ll ans[200005];

ll DFS(int node) {
    ll ret = 0, pre = 0;
    s[node].insert({0, node});
    vector<ll> v;

    for (pii next: tree[node]) {
        ll res = DFS(next.first) + next.second;
        v.emplace_back(res);
    }

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        if (s[node].size() < s[next].size()) {
            swap(s[node], s[next]);
            pre = ret;
            ret = v[i];
            for (pii a: s[next]) s[node].insert({a.first + pre - ret, a.second});
        } else {
            for (pii a: s[next]) s[node].insert({a.first + v[i] - ret, a.second});
        }
    }

    pii find = {L - ret, INF};

    auto idx = s[node].rbegin();
    while (1) {
        pii now = *idx;
        if (now < find) break;
        s[node].erase(now);
        idx = s[node].rbegin();
    }

    ans[node] = s[node].size();

    return ret;
}

void solve() {
    cin >> N >> L;
    for (int i = 2; i <= N; i++) {
        ll a, b;
        cin >> a >> b;
        tree[a].emplace_back(i, b);
    }

    DFS(1);

    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';

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