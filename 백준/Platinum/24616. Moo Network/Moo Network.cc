#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
map<pii, int> id;
pii cow[100005];
vector<ll> arr[15];
vector<pair<ll, pii>> edge;
int parent[100005];

int find(int a) {
    if (parent[a] == a) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(a)] = find(b);
    return;
}

ll dist(pii a, pii b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        cow[i] = {x, y};
        arr[y].push_back(x);
        id[{x, y}] = i;
        parent[i] = i;
    }

    for (int i = 0; i <= 10; i++) sort(arr[i].begin(), arr[i].end());

    for (int i = 1; i <= N; i++) {
        int x = cow[i].first, y = cow[i].second;
        int idx = lower_bound(arr[y].begin(), arr[y].end(), x) - arr[y].begin();
        if (idx) {
            int pre = id[{arr[y][idx - 1], y}];
            edge.push_back({dist(cow[i], cow[pre]), {i, pre}});
        }
        if (idx != arr[y].size() - 1) {
            int nxt = id[{arr[y][idx + 1], y}];
            edge.push_back({dist(cow[i], cow[nxt]), {i, nxt}});
        }

        for (int j = 0; j <= 10; j++) {
            if (j == y) continue;
            idx = upper_bound(arr[j].begin(), arr[j].end(), x) - arr[j].begin();
            if (idx != arr[j].size()) {
                int a = id[{arr[j][idx], j}];
                edge.push_back({dist(cow[i], cow[a]), {i, a}});
            }
            if (idx) {
                int a = id[{arr[j][idx - 1], j}];
                edge.push_back({dist(cow[i], cow[a]), {i, a}});
            }
        }
    }

    int cnt = 0;
    ll ans = 0;

    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        if (cnt == N - 1) break;
        int a = edge[i].second.first, b = edge[i].second.second;
        ll cost = edge[i].first;
        if (find(a) == find(b)) continue;
        merge(a, b);
        ans += cost;
        cnt++;
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