#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, ans;
vector<int> graph[50005];
bitset<50005> edge[50005];

void DFS(int root, int now, int state, int k) {
    ans = max(ans, k);
    if (now == graph[root].size()) return;
    int nxt = graph[root][now];
    
    DFS(root, now + 1, state, k);
    int flag = 0;
    for (int i = 0; i < now; i++) {
        if (!(state & (1 << i))) continue;
        if (!edge[nxt][graph[root][i]]) {
            flag = 1;
            break;
        }
    }
    if (!flag) DFS(root, now + 1, state + (1 << now), k + 1);
    return;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            graph[i].push_back(a), edge[i][a] = 1;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (graph[i].size() < K) DFS(i, 0, 0, 1);
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