#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector<pii> edge;
vector<int> graph[500005], ngraph[500005];
int id[500005], par[500005], in_degree[500005], dp[500005][2], edge_sz[500005];
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
    for (int i = 1; i <= id_cnt; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            dp[i][0] = SCC[i - 1].size();
            dp[i][1] = edge_sz[i];
        }
    }

    for (int i = 1; i <= id_cnt; i++) {
        int now = q.front();
        q.pop();
        for (int next: ngraph[now]) {
            if (--in_degree[next] == 0) q.push(next);
            dp[next][0] = max(dp[next][0], dp[now][0] + (int) SCC[next - 1].size());
            dp[next][1] = max(dp[next][1], dp[now][1] + 1 + edge_sz[next]);
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
        edge.push_back({a, b});
    }

    for (int i = 1; i <= N; i++) {
        if (par[i] == 0) DFS(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int next: graph[i]) {
            if (id[i] != id[next]) {
                ngraph[id[i]].push_back(id[next]);
                in_degree[id[next]]++;
            }
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i].first, b = edge[i].second;
        if (id[a] == id[b]) edge_sz[id[a]]++;
    }

    Topology();

    int a = 0, b = 0;
    for (int i = 1; i <= id_cnt; i++) {
        a = max(a, dp[i][0]);
        b = max(b, dp[i][1]);
    }

    if (a == N) cout << 1 << '\n';
    else cout << 0 << '\n';

    if (b == M) cout << 1 << '\n';
    else cout << 0 << '\n';

    if (a == N && b == M) cout << 1 << '\n';
    else cout << 0 << '\n';

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