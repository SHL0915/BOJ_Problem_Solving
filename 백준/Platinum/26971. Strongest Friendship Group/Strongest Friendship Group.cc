#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M;
vector<int> graph[100005];
int parent[100005], sz[100005], degree[100005], mark[100005];
vector<pii> v;

int find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) {
        parent[a] = b;
        sz[b] += sz[a];
    } else {
        parent[b] = a;
        sz[a] += sz[b];
    }
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    set<pii> s;
    for (int i = 1; i <= N; i++) s.insert({degree[i], i});

    for (int i = 1; i <= N; i++) {
        pii now = *s.begin();
        v.push_back(now);
        s.erase(now);
        mark[now.second] = 1;

        for (int next: graph[now.second]) {
            if (mark[next]) continue;
            s.erase({degree[next], next});
            degree[next]--;
            s.insert({degree[next], next});
        }
    }

    reverse(v.begin(), v.end());
    ll ans = 1;

    memset(mark, 0, sizeof(mark));

    for (int i = 0; i < v.size(); i++) {
        ll now = v[i].second;
        ll d = v[i].first;
        mark[now] = 1;

        for (int next: graph[now]) if (mark[next]) merge(now, next);
        ans = max(ans, d * sz[find(now)]);
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