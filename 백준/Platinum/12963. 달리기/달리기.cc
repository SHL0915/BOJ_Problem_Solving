#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

int N, M;
vector<pii> edge;
int parent[2005];
ll cap[2005];

int find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(a)] = find(b);
    return;
}

void solve() {
    cin >> N >> M;
    cap[0] = 1;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
        if (i) cap[i] = (cap[i - 1] * 3) % mod;
    }

    for (int i = 1; i <= N; i++) parent[i] = i;

    ll ans = 0;
    for (int i = M - 1; i >= 0; i--) {
        int a = edge[i].first, b = edge[i].second;
        if ((find(a) == find(0) && find(b) == find(N - 1)) || (find(a) == find(N - 1) && find(b) == find(0)))
            ans = (ans + cap[i]) % mod;
        else merge(a, b);
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