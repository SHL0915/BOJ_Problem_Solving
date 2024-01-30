#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod = 1e9 + 7;

int N;
vector<pii> tree[500005];

void DFS(int node, int par, ll val, vector<ll> &v) {
    v[node] = val;
    for (auto &[next, cost]: tree[node]) {
        if (next == par) continue;
        DFS(next, node, val + cost, v);
    }
    return;
}

int travel(vector<int> U, vector<int> V, vector<int> W) {
    N = U.size() + 1;
    for (int i = 0; i < N - 1; i++) {
        int u = U[i], v = V[i], w = W[i];
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    vector<ll> distA(N + 5), distB(N + 5);
    int a = -1, b = -1;

    DFS(0, 0, 0, distA);
    ll mx = *max_element(distA.begin(), distA.end());

    for (int i = 0; i < N; i++) if (distA[i] == mx) a = i;

    DFS(a, a, 0, distA);

    mx = *max_element(distA.begin(), distA.end());
    for (int i = 0; i < N; i++) if (distA[i] == mx) b = i;

    DFS(b, b, 0, distB);

    vector<pii> arr;
    for (int i = 0; i < N; i++) arr.push_back({max(distA[i], distB[i]), i});
    sort(arr.begin(), arr.end(), greater<>());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll now = (arr[i].first % mod);
        ans += (now * i) % mod;
    }

    ans *= 2;
    ans %= mod;

    return ans;
}