#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K, cnt, id_cnt;
int arr[1005];
vector<int> graph[1005], ngraph[1005];
int id[1005], par[1005], in_degree[1005], mark[1005], parent[1005], sz[1005], range[1005];
vector<vector<int>> SCC;
int dp[1005], ans[1005], temp[1005];
stack<int> st;

int Find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = Find(parent[a]);
}

void Merge(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (a > b) {
        parent[a] = b;
        sz[b] += sz[a];
    } else {
        parent[b] = a;
        sz[a] += sz[b];
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

void Topology() {
    queue<int> q;
    for (int i = 1; i <= id_cnt; i++) {
        if (in_degree[i] == 0) {
            dp[i] = SCC[i - 1].size();
            q.push(i);
        }
    }

    for (int i = 1; i <= id_cnt; i++) {
        int now = q.front();
        q.pop();
        for (int next: ngraph[now]) {
            if (--in_degree[next] == 0) q.push(next);
            dp[next] = max(dp[next], dp[now] + (int) SCC[next - 1].size());
        }
    }

    return;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        parent[i] = i;
        graph[arr[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) if (par[i] == 0) DFS(i);

    for (int i = 1; i <= id_cnt; i++) sz[i] = SCC[i - 1].size();

    for (int i = 1; i <= N; i++) {
        for (int next: graph[i]) {
            if (id[i] == id[next]) continue;
            ngraph[id[i]].push_back(id[next]);
            in_degree[id[next]]++;
            Merge(id[i], id[next]);
        }
    }

    Topology();

    memset(range, INF, sizeof(range));

    for (int i = 1; i <= id_cnt; i++) range[Find(i)] = min(range[Find(i)], dp[i]);

    temp[0] = 1;

    for (int i = 1; i <= id_cnt; i++) {
        if (mark[Find(i)]) continue;
        mark[Find(i)] = 1;

        int l = range[Find(i)], r = sz[Find(i)];

        for (int j = 0; j <= K; j++) {
            if (temp[j] == 0) continue;
            ans[j] = 1;
            for (int k = l; k <= r; k++) ans[j + k] = 1;
        }

        swap(temp, ans);
    }

    swap(temp, ans);

    for (int i = K; i >= 0; i--) {
        if (ans[i]) {
            cout << i;
            return;
        }
    }

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