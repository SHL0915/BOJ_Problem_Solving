#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[2005];
vector<pair<int, long double>> graph[2005];

long double dist(pii a, pii b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

long double Dijkstra(int s) {
    vector<long double> d(N + 5, 1e18);
    priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<>> pq;
    pq.push({0, s});
    d[s] = 0;
    
    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        int now = t.second;
        long double v = t.first;
        if (d[now] < v) continue;
        
        for (auto i: graph[now]) {
            int next = i.first;
            long double cost = i.second;
            if (d[next] > v + cost) {
                d[next] = v + cost;
                pq.push({v + cost, next});
            }
        }
    }
    
    return d[N + 1];
}

void solve() {
    pii pos;
    cin >> pos.first >> pos.second;
    cin >> N;
    arr[N + 1] = pos;
    arr[0] = {0, 0};
    
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    
    for (int i = 0; i <= N + 1; i++) {
        for (int j = i + 1; j <= N + 1; j++) {
            long double d = dist(arr[i], arr[j]);
            if (i == 0 && j == N + 1) {
                graph[i].push_back({j, d});
                graph[j].push_back({i, d});
            } else if (i == 0 || j == N + 1) {
                graph[i].push_back({j, max((long double) 0, d - 1)});
                graph[j].push_back({i, max((long double) 0, d - 1)});
            } else {
                graph[i].push_back({j, max((long double) 0, d - 2)});
                graph[j].push_back({i, max((long double) 0, d - 2)});
            }
        }
    }
    
    cout << Dijkstra(0);
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(12);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}