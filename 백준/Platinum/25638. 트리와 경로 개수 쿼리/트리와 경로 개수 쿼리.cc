#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, rcnt, bcnt;
int arr[100005];
ll ans[100005];
pii sum[100005];
vector<int> tree[100005];

void DFS(int node, int par) {
    if (arr[node]) sum[node].first++;
    else sum[node].second++;
    
    ll a = 0, b = 0;
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node);
        sum[node].first += sum[next].first;
        sum[node].second += sum[next].second;
        ans[node] += sum[next].first * b + sum[next].second * a;
        a += sum[next].first, b += sum[next].second;
    }
    
    ll ta = rcnt - sum[node].first, tb = bcnt - sum[node].second;
    ans[node] += ta * b + tb * a;
    
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i], rcnt += arr[i];
    bcnt = N - rcnt;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    DFS(1, 0);
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int a;
        cin >> a;
        cout << ans[a] << '\n';
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