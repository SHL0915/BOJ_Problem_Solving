#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector<int> graph[100005], ngraph[200005];
int id[100005], par[100005], in_degree[200005], dp[200005];
vector<vector<int>> SCC;
stack<int> st;

int DFS(int node) {
    par[node] = ++cnt;
    st.push(node);
    int ret = par[node];
    
    for (int next: graph[node]) {
        if (par[next] == 0) ret = min(ret, DFS(next));
        else if (id[next] == 0) ret = min(ret, par[next]);
    }
    
    if (ret == par[node]) {
        id_cnt++;
        vector<int> v;
        while (st.size()) {
            int t = st.top();
            st.pop();
            id[t] = id_cnt;
            v.push_back(t);
            if (t == node) break;
        }
        SCC.push_back(v);
    }
    
    return ret;
}

void Topology() {
    queue<int> q;
    for (int i = 1; i <= 2 * id_cnt; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            if (i == id[1]) dp[i] = SCC[i - 1].size();
        }
    }
    
    for (int i = 1; i <= 2 * id_cnt; i++) {
        int now = q.front();
        q.pop();
        for (int next: ngraph[now]) {
            if (--in_degree[next] == 0) q.push(next);
            if (now == id[1]) dp[now] = max(dp[now], (int)SCC[now - 1].size());
            if (dp[now]) {
                if (next <= id_cnt) dp[next] = max(dp[next], dp[now] + (int) SCC[next - 1].size());
                else dp[next] = max(dp[next], dp[now] + (int) SCC[next - 1 - id_cnt].size());
            }
        }
    }
    
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);
    
    for (int i = 1; i <= N; i++) {
        for (int next: graph[i]) {
            if (id[i] != id[next]) {
                in_degree[id[next]]++;
                ngraph[id[i]].push_back(id[next]);
                ngraph[id[i] + id_cnt].push_back(id[next] + id_cnt);
                in_degree[id[next] + id_cnt]++;
                ngraph[id[next]].push_back(id[i] + id_cnt);
                in_degree[id[i] + id_cnt]++;
            }
        }
    }
    
    Topology();
    
    int ans = max(dp[id[1]], dp[id[1] + id_cnt] - (int) SCC[id[1] - 1].size());
    
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