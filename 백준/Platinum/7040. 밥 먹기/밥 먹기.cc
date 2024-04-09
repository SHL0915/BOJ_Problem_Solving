#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int N, A, B;
vector<pair<pii, ll>> edge;
ll dist[1005];

int BF(int start) {
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[start] = 0;
    
    for (int i = 0; i < N; i++) {
        for (auto &[a, b]: edge) dist[a.second] = min(dist[a.second], dist[a.first] + b);
    }
    
    for (auto &[a, b]: edge) {
        if (dist[a.second] > dist[a.first] + b) {
            return 1;
        }
    }
    
    return 0;
}

void solve() {
    cin >> N >> A >> B;
    for (int i = 0; i < A; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{a, b}, c});
    }
    for (int i = 0; i < B; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.push_back({{b, a}, -c});
    }
    
    for (int i = 0; i < N; i++) {
        for (auto &[a, b]: edge) dist[a.second] = min(dist[a.second], dist[a.first] + b);
    }
    
    for (auto &[a, b]: edge) {
        if (dist[a.second] > dist[a.first] + b) {
            cout << -1;
            return;
        }
    }
    
    BF(1);
    
    if (dist[N] > 1e15) cout << -2;
    else cout << dist[N];
    
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