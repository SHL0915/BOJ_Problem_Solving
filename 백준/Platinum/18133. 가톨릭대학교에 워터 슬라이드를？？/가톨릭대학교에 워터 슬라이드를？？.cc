#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, cnt, id_cnt;
vector<int> graph[100005];
int id[100005], par[100005], in_degree[100005];
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
        while (st.size()) {
            int t = st.top();
            st.pop();
            id[t] = id_cnt;
            if (t == node) break;
        }
    }

    return ret;
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
            if (id[i] != id[next]) in_degree[id[next]]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= id_cnt; i++) {
        if (in_degree[i] == 0) ans++;
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