#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 1000005, INF = 36501;

int N, M;
vector<int> graph[sz];
int par[sz], id[sz], id_cnt, cnt, check[sz], dp[sz], dp2[sz];
stack<int> st;

int DFS(int node) {
    par[node] = ++cnt;
    int ret = cnt;
    st.push(node);
    for (int next: graph[node]) {
        if (par[next] == 0) ret = min(ret, DFS(next));
        else if (id[next] == 0) ret = min(ret, par[next]);
    }
    
    if (ret == par[node]) {
        id_cnt++;
        while (1) {
            int t = st.top();
            st.pop();
            id[t] = id_cnt;
            if (t == node) break;
        }
    }
    
    return ret;
}

int DP(int now) {
    if (now == N + 1) {
        if (check[id[now]]) return INF;
        else return 1;
    }
    int &ret = dp[now];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int next: graph[now]) {
        ret += DP(next);
        if (ret >= INF) ret = INF;
    }
    if (ret && check[id[now]]) ret = INF;
    
    return ret;
}

int DP2(int now) {
    if (now == N + 1) {
        if (check[id[now]]) return INF;
        else return 1;
    }
    int &ret = dp2[now];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int next: graph[now]) {
        ret += max(DP(next), DP2(next));
        if (ret >= INF) ret = INF;
    }
    if (ret && check[id[now]]) ret = INF;
    
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for (int i = 1; i <= N + 1; i++) {
        if (!par[i]) DFS(i);
    }
    
    for (int i = 1; i <= N + 1; i++) {
        for (int a: graph[i]) {
            if (id[i] == id[a]) check[id[i]] = 1;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp));
    int M = 0;
    
    vector<int> ans;
    
    for (int i = 1; i <= N; i++) M = max(M, DP(i));
    for (int i = 1; i <= N; i++) M = max(M, DP2(i));
    
    for (int i = 1; i <= N; i++) {
        if (DP2(i) == M) ans.push_back(i);
    }
    
    if (M == INF) cout << "zawsze\n";
    else cout << M << '\n';
    
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << " ";
    
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