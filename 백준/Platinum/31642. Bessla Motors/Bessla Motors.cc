#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, M, C, R, K;
vector<pii> graph[50005];
map<ll, ll> dist[50005];

void Dijkstra() {
    priority_queue<pair<pii, ll>, vector<pair<pii, ll>>, greater<>> pq;
    for (int i = 1; i <= C; i++) {
        dist[i][i] = 0;
        pq.push({{0, i}, i});
    }
    while (pq.size()) {
        pair<pii, ll> t = pq.top();
        pq.pop();
        ll v = t.first.first, s = t.first.second, now = t.second;
        
        if (dist[now].count(s)) {
            if (dist[now][s] < v) continue;
        } else continue;
        
        for (pii next: graph[now]) {
            ll nv = v + next.second, n = next.first;
            if (nv > R) continue;
            if (dist[n].count(s)) {
                if (dist[n][s] <= nv) continue;
                else {
                    dist[n][s] = nv;
                    pq.push({{nv, s}, n});
                }
            } else {
                if (dist[n].size() < K) {
                    dist[n][s] = nv;
                    pq.push({{nv, s}, n});
                } else {
                    pii m = {-1, -1};
                    for (auto a: dist[n]) {
                        if (m.second < a.second) m = a;
                    }
                    if (nv >= m.second) continue;
                    dist[n].erase(m.first);
                    dist[n][s] = nv;
                    pq.push({{nv, s}, n});
                }
            }
        }
    }
    return;
}

void solve() {
    cin >> N >> M >> C >> R >> K;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    Dijkstra();
    vector<int> ans;
    for (int i = C + 1; i <= N; i++) {
        if (dist[i].size() == K) {
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << '\n';
    
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