#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, T;
vector<pii> edge;
vector<int> graph[100005];
int arr[100005], in_degree[100005], dp[100005];

void toposort(int root, int k) {
    dp[root] = k;
    queue<int> q;
    for (int i = 1; i <= N; i++) if (!in_degree[i]) q.push(i);
    
    while (q.size()) {
        int f = q.front();
        q.pop();
        
        if (dp[f]) {
            int sz = graph[f].size();
            if (!sz) continue;
            int a = (dp[f] - 1) / sz, b = (dp[f] - 1) % sz;
            for (int i = 0; i < sz; i++) {
                int next = graph[f][(arr[f] + i) % sz];
                if (--in_degree[next] == 0) q.push(next);
                if (i <= b) dp[next] += a + 1;
                else dp[next] += a;
            }
        } else {
            for (int next: graph[f]) {
                if (--in_degree[next] == 0) q.push(next);
            }
        }
    }
}

int DFS(int node) {
    if (arr[node] == -1) return node;
    int sz = graph[node].size();
    return DFS(graph[node][(arr[node] + dp[node]) % sz]);
}

void solve() {
    cin >> N >> K >> T;
    
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
    }
    
    int root = -1;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == 1) root = i;
    }
    
    for (int i = 0; i < K; i++) {
        int a = edge[i].first, b = edge[i].second;
        if (arr[a] > arr[b]) swap(a, b);
        graph[a].push_back(b), in_degree[b]++;
    }
    
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == -1) continue;
        else arr[i] = lower_bound(graph[i].begin(), graph[i].end(), arr[i]) - graph[i].begin();
    }
    
    toposort(root, T - 1);
    
    cout << DFS(root);
    
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