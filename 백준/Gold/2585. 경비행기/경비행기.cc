#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f;

int N, K;
pii arr[1005];
vector<pii> graph[1005];
int dist[1005];

ll sqrdist(pii a, pii b);

bool chk(ll k);

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i].first >> arr[i].second;
    arr[N + 1] = {10000, 10000};
    
    for (int i = 0; i <= N + 1; i++) {
        for (int j = i + 1; j <= N + 1; j++) {
            graph[i].push_back({j, sqrdist(arr[i], arr[j])});
            graph[j].push_back({i, sqrdist(arr[i], arr[j])});
        }
    }
    
    ll l = 0, r = 200005;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (chk(mid) == true) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
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

ll sqrdist(pii a, pii b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

bool chk(ll k) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    
    q.push(0);
    dist[0] = 0;
    
    while (q.size()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            if (dist[next] != -1) continue;
            
            if (graph[now][i].second > k * k * 100) continue;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
        
    if (dist[N + 1] == -1 || dist[N + 1] > K + 1) return false;
    else return true;
}