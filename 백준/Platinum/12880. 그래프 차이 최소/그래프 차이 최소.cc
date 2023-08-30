#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt, id_cnt;
int adj[55][55], par[55], id[55];
vector<pair<int, pii>> edge;
vector<int> graph[55];
vector<vector<int>> SCC;
stack<int> st;

void init() {
    memset(par, 0, sizeof(par));
    memset(id, 0, sizeof(id));
    cnt = 0;
    id_cnt = 0;
    for (int i = 1; i <= N; i++) graph[i].clear();
    SCC.clear();
    return;
}

int DFS(int node) {
    par[node] = ++cnt;
    int ret = cnt;
    st.push(node);
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (par[next] == 0) ret = min(ret, DFS(next));
        else if (id[next] == 0) ret = min(ret, par[next]);
    }

    if (ret == par[node]) {
        id_cnt++;
        vector<int> v;
        while (1) {
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
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
            edge.push_back({adj[i][j], {i, j}});
        }
    }

    int a = 0x3f3f3f3f;

    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        int l = edge[i].first, r = 150000;
        int ans = -1;
        while (l <= r) {
            init();
            int mid = (l + r) / 2;
            for (int j = i; j < edge.size(); j++) {
                if (edge[j].first > mid) break;
                graph[edge[j].second.first].push_back(edge[j].second.second);
            }

            for (int j = 1; j <= N; j++) {
                if (par[j] == 0) DFS(j);
            }

            if (SCC.size() == 1 && SCC[0].size() == N) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        if (ans == -1) continue;
        a = min(a, ans - edge[i].first);
    }

    cout << a;
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