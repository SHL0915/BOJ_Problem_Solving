#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, S, cnt, id_cnt;
int arr[100005];
vector<int> graph[100005], ngraph[100005];
int id[100005], par[100005], dp[100005], in_degree[100005];
vector<vector<int>> SCC;
stack<int> st;

void Topology() {
    queue<int> q;
    for (int i = 1; i <= id_cnt; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            if (i == id[S]) dp[i] = SCC[i - 1].size();
        }
    }

    for (int i = 1; i <= id_cnt; i++) {
        int now = q.front();
        q.pop();

        if (now == id[S]) dp[now] = SCC[now - 1].size();

        for (int next: ngraph[now]) {
            if (--in_degree[next] == 0) q.push(next);
            if (dp[now]) dp[next] = max(dp[next], dp[now] + (int) SCC[next - 1].size());
        }
    }

    return;
}

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

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (i - arr[i] >= 1) graph[i].push_back(i - arr[i]);
        if (i + arr[i] <= N) graph[i].push_back(i + arr[i]);
    }
    cin >> S;

    for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);

    for (int i = 1; i <= N; i++) {
        for (int next: graph[i]) {
            if (id[i] != id[next]) {
                ngraph[id[i]].push_back(id[next]);
                in_degree[id[next]]++;
            }
        }
    }

    Topology();

    int ans = 0;
    for (int i = 1; i <= id_cnt; i++) ans = max(ans, dp[i]);

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