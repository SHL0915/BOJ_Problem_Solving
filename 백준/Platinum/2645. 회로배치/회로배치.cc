#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int INF = 0x3f3f3f3f;

int N, K, M;
pii S, E;
int arr[55][55];
pii path[55][55];
int dist[55][55];
vector<pii> ans;

void Dijkstra(pii start);

void FindPath(pii now, pii prev);

void solve() {
    cin >> N;
    cin >> S.first >> S.second;
    cin >> E.first >> E.second;
    cin >> K >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        vector<pii> v;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> y >> x;
            v.push_back({y, x});
        }
        for (int j = 1; j < k; j++) {
            pii now = v[j], prev = v[j - 1];
            
            if (now.second == prev.second) {
                for (int a = min(now.first, prev.first); a <= max(now.first, prev.first); a++) arr[a][now.second] = 1;
            } else {
                for (int a = min(now.second, prev.second); a <= max(now.second, prev.second); a++)
                    arr[now.first][a] = 1;
            }
        }
    }
    
    Dijkstra(S);
    
    cout << dist[E.first][E.second] << '\n';
    ans.push_back(E);
    
    FindPath(path[E.first][E.second], E);
    ans.push_back(S);
    
    cout << ans.size() << " ";
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i].first << " " << ans[i].second << " ";
    
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

void Dijkstra(pii start) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    
    dist[start.first][start.second] = 1;
    pq.push({1, start});
    
    while (pq.size()) {
        pair<int, pii> t = pq.top();
        pq.pop();
        
        int x = t.second.second;
        int y = t.second.first;
        int val = t.first;
        if (dist[y][x] < val) continue;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            int nval = val;
            if (arr[ny][nx] == 0) nval++;
            else nval += K;
            
            if (dist[ny][nx] > nval) {
                path[ny][nx] = {y, x};
                dist[ny][nx] = nval;
                pq.push({nval, {ny, nx}});
            }
        }
    }
}

void FindPath(pii now, pii prev) {    
    if (prev == E) {
        FindPath(path[now.first][now.second], now);
        return;
    }
    pii b = ans.back();
    
    if (b.first == prev.first) {
        if (now.first != prev.first) ans.push_back(prev);
    }
    
    if (b.second == prev.second) {
        if (now.second != prev.second) ans.push_back(prev);
    }
    
    if (now == S) return;
    FindPath(path[now.first][now.second], now);
    return;
}