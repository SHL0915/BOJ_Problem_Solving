#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, B, S, R;
vector<pii> graph[5005], rgraph[5005];
int dist[5005], rdist[5005];
ll arr[5005], psum[5005];
ll dp[5005][5005];

void Dijkstra1(int start) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second, d = t.first;
        if (dist[now] < d) continue;
        for (auto &[next, cost]: graph[now]) {
            int nd = d + cost;
            if (dist[next] > nd) {
                dist[next] = nd;
                pq.push({nd, next});
            }
        }
    }
    
    return;
}

void Dijkstra2(int start) {
    memset(rdist, 0x3f, sizeof(rdist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    rdist[start] = 0;
    pq.push({0, start});
    
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int now = t.second, d = t.first;
        if (rdist[now] < d) continue;
        for (auto &[next, cost]: rgraph[now]) {
            int nd = d + cost;
            if (rdist[next] > nd) {
                rdist[next] = nd;
                pq.push({nd, next});
            }
        }
    }
    
    return;
}

ll cost(int l, int r) {
    return (r - l) * (psum[r] - psum[l - 1]);
}

void dnc(int k, int s, int e, int l, int r) {
    if (s > e) return;
    int m = (s + e) / 2;
    int idx = -1;
    for (int i = l; i <= min(m, r); i++) {
        if (dp[k][m] > dp[k - 1][i] + cost(i + 1, m)) {
            dp[k][m] = dp[k - 1][i] + cost(i + 1, m);
            idx = i;
        }
    }
    
    dnc(k, s, m - 1, l, idx);
    dnc(k, m + 1, e, idx, r);
    return;
}

void solve() {
    cin >> N >> B >> S >> R;
    for (int i = 0; i < R; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].push_back({v, l});
        rgraph[v].push_back({u, l});
    }
    
    Dijkstra1(B + 1);
    Dijkstra2(B + 1);
    
    vector<int> v(B);
    iota(v.begin(), v.end(), 1);
    
    sort(v.begin(), v.end(), [&](int a, int b) {
        return dist[a] + rdist[a] < dist[b] + rdist[b];
    });
    
    for (int i = 1; i <= B; i++) arr[i] = dist[v[i - 1]] + rdist[v[i - 1]];
    for (int i = 1; i <= B; i++) psum[i] = arr[i] + psum[i - 1];
    
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= B; i++) dp[1][i] = cost(1, i);
    for (int i = 2; i <= S; i++) dnc(i, 1, B, 1, B);
    
    cout << dp[S][B];
    
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