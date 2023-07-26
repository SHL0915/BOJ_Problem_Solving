#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt, id_cnt;
vector<int> graph[200005];
vector<int> ngraph[200005];
int id[200005], par[200005], in_degree[200005], dp[200005];
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
            dp[i] = SCC[i - 1].size();
        }
    }

    for (int i = 1; i < id_cnt; i++) {
        int now = q.front();
        q.pop();
        for (int next: ngraph[now]) {
            if (--in_degree[next] == 0) q.push(next);
            dp[next] = max(dp[next], (int) SCC[next - 1].size() + dp[now]);
        }
    }

    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int now = i;
        int sum = 0;
        while (now) {
            sum += now % 10;
            now /= 10;
        }
        graph[i].push_back((i + sum - 1) % N + 1);
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