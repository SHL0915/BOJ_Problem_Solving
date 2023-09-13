#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, ccnt, id_cnt;
int arr[3005][5];
pii cand[3005];
int idx[3005][3005];
pii rev[6005];
vector<int> graph[15005];
int adj[3005][3005], mark[15005], id[15005], ans[15005], out[3005];
vector<vector<int>> SCC;
stack<int> st;

inline int convert(int a) {
    if (a >= 0) return a * 2 - 1;
    else return -a * 2;
}

void add_edge(int i, int j, int a, int b) {
    int f = idx[i][a], s = idx[j][b];
    if (a == b) {
        graph[convert(f)].push_back(convert(-s));
        graph[convert(s)].push_back(convert(-f));
    }
    if (adj[a][b] != 0) {
        if (arr[i][adj[a][b]] != arr[j][adj[a][b]]) {
            graph[convert(f)].push_back(convert(-s));
            graph[convert(s)].push_back(convert(-f));
        }
    }
    return;
}

int DFS(int node) {
    int ret = mark[node] = ++ccnt;
    st.push(node);

    for (int next: graph[node]) {
        if (mark[next] == 0) ret = min(ret, DFS(next));
        else if (id[next] == 0) ret = min(ret, mark[next]);
    }

    if (ret == mark[node]) {
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
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 4; j++) cin >> arr[i][j];
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        cand[i] = {a, b};
        if (a == b) {
            idx[i][a] = ++cnt;
            rev[cnt] = {i, a};
            graph[convert(-cnt)].push_back(convert(cnt));
        } else {
            int f = idx[i][a] = ++cnt;
            rev[cnt] = {i, a};
            int s = idx[i][b] = ++cnt;
            rev[cnt] = {i, b};
            graph[convert(-f)].push_back(convert(s));
            graph[convert(-s)].push_back(convert(f));
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int a = cand[i].first, b = cand[i].second, c = cand[j].first, d = cand[j].second;
            add_edge(i, j, a, c);
            add_edge(i, j, b, c);
            add_edge(i, j, a, d);
            add_edge(i, j, b, d);
        }
    }

    for (int i = 1; i <= 2 * cnt; i++) {
        if (mark[i] == 0) DFS(i);
    }

    for (int i = 1; i <= cnt; i++) {
        if (id[convert(i)] == id[convert(-i)]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES\n";
    reverse(SCC.begin(), SCC.end());
    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < SCC.size(); i++) {
        for (int a: SCC[i]) {
            int now = (a + 1) / 2;
            if (ans[now] != -1) continue;
            ans[now] = (a % 2) ^ 1;
        }
    }

    for (int i = 1; i <= cnt; i++) {
        if (ans[i] == 1) {
            int a = rev[i].first, b = rev[i].second;
            out[b] = a;
        }
    }

    for (int i = 1; i <= N; i++) {
        assert(out[i] != 0);
        cout << out[i] << " ";
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