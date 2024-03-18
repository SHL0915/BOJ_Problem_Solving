#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005], sz[100005], cnt[100005];
vector<int> tree[100005];

void DFS(int node, int par) {
    if (par && tree[node].size() == 1) sz[node]++;
    
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node);
        sz[node] += sz[next];
    }
    
    return;
}

int find_ans(int node, int par) {
    if (par && tree[node].size() == 1) sz[node]++;
    
    int ret = 0;
    
    for (int next: tree[node]) {
        if (next == par) continue;
        ret += find_ans(next, node);
        sz[node] += sz[next];
    }
    
    ret += min(sz[node], cnt[node]);
    sz[node] = max(0, sz[node] - cnt[node]);
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    DFS(1, 0);
    
    for (int i = 0; i < sz[1]; i++) cnt[arr[i]]++;
    memset(sz, 0, sizeof(sz));
    
    cout << find_ans(1, 0);
    
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