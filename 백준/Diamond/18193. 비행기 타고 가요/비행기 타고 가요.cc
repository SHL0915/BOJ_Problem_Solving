#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, M, K, cnt = 3000000;
vector<pii> graph[3500005];
ll dist[3500005];

void init(int node, int l, int r);
void convert(vector<int> &v, int node, int s, int e, int l, int r);
void Dijkstra(int start);

void solve() {
    cin >> N >> M >> K;
    init(1, 1, N);
    
    for (int i = 0; i < M; i++) {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        
        vector<int> in, out;
        convert(in, 1, 1, N, b, c);
        convert(out, 1, 1, N, d, e);
        
        for(int j : in) graph[j].push_back({cnt, 0});
        for(int j : out) graph[cnt].push_back({j + 4 * N, a});
        cnt++;
    }
    
    vector<int> S;
    convert(S, 1, 1, N, K, K);
    
    Dijkstra(S[0]);
    
    for (int i = 1; i <= N; i++) {
        vector<int> now;
        convert(now, 1, 1, N, i, i);
        if (dist[now[0]] == INF) cout << -1 << " ";
        else cout << dist[now[0]] << " ";
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

void init(int node, int l, int r) {
    if (l == r) {
        graph[node + 4 * N].push_back({node, 0});
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    graph[node * 2].push_back({node, 0});
    graph[node * 2 + 1].push_back({node, 0});
    graph[node + 4 * N].push_back({node * 2 + 4 * N, 0});
    graph[node + 4 * N].push_back({node * 2 + 1 + 4 * N, 0});
    return;
}

void convert(vector<int> &v, int node, int s, int e, int l, int r) {
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        v.push_back(node);
        return;
    }
    int m = (s + e) / 2;
    convert(v, node * 2, s, m, l, r);
    convert(v, node * 2 + 1, m + 1, e, l, r);
    return;
}

void Dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;
    
    pq.push({0, start});
    dist[start] = 0;
    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        ll val = t.first;
        int now = t.second;
        if (dist[now] < val) continue;
        
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            ll nval = val + graph[now][i].second;
            if (dist[next] > nval) {
                dist[next] = nval;
                pq.push({nval, next});
            }
        }
    }
}