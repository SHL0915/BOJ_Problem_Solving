#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, A, B, C;
vector<pii> graph[1005];
int dist[1005];
vector<int> path[1005];
vector<pii> ans_vector;

void Dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= N; i++) path[i].clear();

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second, v = t.first;

        if (dist[now] < v) continue;

        for (auto &[next, cost]: graph[now]) {
            int ncost = cost + v;
            if (dist[next] > ncost) {
                dist[next] = ncost;
                path[next].clear();
                path[next].push_back(now);
                pq.push({ncost, next});
            } else if (dist[next] == ncost) path[next].push_back(now);
        }
    }

    return;
}

void find_path(int now, int destination) {
    if (now == destination) return;
    ans_vector.push_back({now, path[now].back()});
    find_path(path[now].back(), destination);
}


void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> A >> B >> C;

    int ans = 1e9;

    for (int i = 1; i <= N; i++) {
        Dijkstra(i);
        ans = min(ans, dist[A] + dist[B] + dist[C]);
    }

    for (int i = 1; i <= N; i++) {
        Dijkstra(i);
        if (ans == dist[A] + dist[B] + dist[C]) {
            find_path(A, i);
            find_path(B, i);
            find_path(C, i);
            break;
        }
    }

    cout << ans << " " << ans_vector.size() << '\n';
    for (pii i: ans_vector) cout << i.first << " " << i.second << '\n';

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