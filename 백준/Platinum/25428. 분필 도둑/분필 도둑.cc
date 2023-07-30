#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
ll arr[100005];
int parent[100005], sz[100005];
vector<pair<ll, pii>> edge;

int Find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = Find(parent[a]);
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    parent[b] = a;
    sz[a] += sz[b];
    return;
}

void solve() {
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ans = max(ans, arr[i]);
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({min(arr[a], arr[b]), {a, b}});
    }
    
    sort(edge.begin(), edge.end(), greater<>());
    
    int SZ = 1;
    
    for (int i = 0; i < N - 1; i++) {
        int a = edge[i].second.first, b = edge[i].second.second;
        Merge(a, b);
        SZ = max(SZ, sz[Find(a)]);
        ans = max(ans, edge[i].first * SZ);
    }
    
    cout << ans;
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