#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, M;
vector<pair<ll, pii>> edge;
ll parent[100005], arr[100005], ans[100005];
map<ll, ll> m[100005];

int find(int a) {
    if (parent[a] == a) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b, ll w) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (m[a].size() > m[b].size()) swap(a, b);

    for (auto i = m[a].begin(); i != m[a].end(); i++) {
        ll id = (*i).first, cnt = (*i).second;
        ans[id] += w * cnt * m[b][id];
        m[b][id] += cnt;
    }

    parent[a] = b;
    return;
}

void solve() {
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        parent[i] = i;
        m[i][arr[i]]++;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end(), greater<>());
    for (int i = 0; i < M; i++) {
        int a = edge[i].second.first, b = edge[i].second.second;
        ll w = edge[i].first;
        if (find(a) == find(b)) continue;
        merge(a, b, w);
    }

    for (int i = 1; i <= K; i++) cout << ans[i] << '\n';

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