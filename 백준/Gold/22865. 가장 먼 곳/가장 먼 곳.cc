#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, A, B, C;
vector<pii> graph[100005];
int dist[100005];

void Dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[A] = 0;
    dist[B] = 0;
    dist[C] = 0;
    pq.push({0, A});
    pq.push({0, B});
    pq.push({0, C});
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second, v = t.first;
        if (dist[now] < v) continue;
        for (pii i: graph[now]) {
            int next = i.first, cost = i.second;
            if (dist[next] > v + cost) {
                dist[next] = v + cost;
                pq.push({v + cost, next});
            }
        }
    }
    return;
}

void solve() {
    cin >> N;
    cin >> A >> B >> C;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    Dijkstra();
    
    int m = -1;
    for (int i = 1; i <= N; i++) m = max(m, dist[i]);
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] == m) {
            cout << i;
            break;
        }
    }
    
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