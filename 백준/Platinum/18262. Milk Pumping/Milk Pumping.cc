#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M;
vector<pair<int, pii>> graph[1005];
ll dist[1005][1005];

void Dijkstra(int start, int f) {
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[start][f] = 0;
    pq.push({0, start});

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second;
        ll val = t.first;
        if (dist[now][f] < val) continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            ll nval = val + graph[now][i].second.first;
            if (graph[now][i].second.second < f) continue;

            if (dist[next][f] > nval) {
                dist[next][f] = nval;
                pq.push({nval, next});
            }
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({b, {c, d}});
        graph[b].push_back({a, {c, d}});
    }

    memset(dist, INF, sizeof(dist));

    for (int i = 1; i <= 1000; i++) Dijkstra(1, i);

    vector<pii> arr;
    for (int i = 1; i <= 1000; i++) {
        if (dist[N][i] == INF) continue;
        arr.push_back({i, dist[N][i]});
    }

    sort(arr.begin(), arr.end(), [&](pii a, pii b) {
        return a.first * b.second > b.first * a.second;
    });

    cout << arr[0].first * 1000000LL / arr[0].second;
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