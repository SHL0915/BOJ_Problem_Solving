#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, ans;
set<int> graph[50005];
int ok[50005];

void DFS(int root, int now, int state, int k) {
    ans = max(ans, k);
    if (now == graph[root].size()) return;
    int idx = 0, nxt = -1;
    
    for (auto i: graph[root]) {
        if (idx == now) {
            nxt = i;
            break;
        }
        idx++;
    }
    
    DFS(root, now + 1, state, k);
    int flag = 0;
    idx = 0;
    for (auto i: graph[root]) {
        if (state & (1 << idx)) {
            if (!graph[nxt].count(i)) {
                flag = 1;
                break;
            }
        }
        idx++;
    }
    if (!flag) DFS(root, now + 1, state | (1 << now), k + 1);
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
            graph[i].insert(a);
        }
    }
    
    set<pii> s;
    for (int i = 0; i < N; i++) {
        s.insert({graph[i].size(), i});
    }
    
    while (s.size()) {
        pii now = *s.begin();
        if (ok[now.second]) s.erase(now);
        else {
            s.erase(now);
            DFS(now.second, 0, 0, 1);
            for (auto i: graph[now.second]) {
                s.erase({graph[i].size(), i});
                graph[i].erase(now.second);
            }
            for (auto i: graph[now.second]) s.insert({graph[i].size(), i});
            ok[now.second] = 1;
        }
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