#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[1005];
int cnt[1005], vst[1005];

void DFS(int node, int p) {
    if (vst[node] == p) return;
    vst[node] = p;
    cnt[node]++;
    for (int next: graph[node]) DFS(next, p);
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for (int i = 1; i <= N; i++) {
        DFS(i, i);
        for (int j = 1; j <= N; j++) {
            if (vst[j] == i) cnt[i]++;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) ans += (N - cnt[i] + 1);
    
    cout << ans / 2;
    
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