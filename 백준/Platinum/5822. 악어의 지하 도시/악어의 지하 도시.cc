#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, K;
vector<pii> graph[100005];
ll dist[100005][2];
int vst[100005];
vector<int> arr;

void Dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    for (int i = 0; i < K; i++) {
        int now = arr[i];
        dist[now][0] = dist[now][1] = 0;
        pq.push({0, now});
    }
    
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second;
        if (vst[now]) continue;
        vst[now] = 1;
        for (auto &[next, cost]: graph[now]) {
            if(vst[next]) continue;
            ll nval = cost + dist[now][1];
            if (dist[next][0] > nval) {
                dist[next][1] = dist[next][0];
                dist[next][0] = nval;
                pq.push({dist[next][1], next});
            } else if (dist[next][1] > nval) {
                dist[next][1] = nval;
                pq.push({dist[next][1], next});
            }
        }
    }
    
    return;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    Dijkstra();
    
    cout << dist[0][1];
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