#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, L;
vector<pii> tree[200005];
priority_queue<ll> pq[200005];
ll ans[200005];

ll DFS(int node) {
    ll ret = 0;
    pq[node].push(0);
    vector<ll> v;

    for (pii next: tree[node]) {
        ll res = DFS(next.first) + next.second;
        v.emplace_back(res);
    }

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        if (pq[node].size() < pq[next].size()) {
            swap(pq[node], pq[next]);
            while (pq[next].size()) {
                ll t = pq[next].top();
                pq[next].pop();
                pq[node].push(t + ret - v[i]);
            }
            ret = v[i];
        } else {
            while (pq[next].size()) {
                ll t = pq[next].top();
                pq[next].pop();
                pq[node].push(t + v[i] - ret);
            }
        }
    }

    while (pq[node].size()) {
        ll now = pq[node].top();
        if (now <= L - ret) break;
        pq[node].pop();
    }

    ans[node] = pq[node].size();

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