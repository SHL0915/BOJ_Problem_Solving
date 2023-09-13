#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, ccnt, id_cnt;
int arr[3005][5];
pii cand[3005];
map<pii, int> m;
pii rev[6005];
vector<int> graph[15005];
int adj[3005][3005], mark[6005], id[6005], ans[6005], out[3005];
vector<vector<int>> SCC;
stack<int> st;

inline int convert(int a) {
    if (a >= 0) return a * 2 - 1;
    else return -a * 2;
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
            m[{i, a}] = ++cnt;
            rev[cnt] = {i, a};
            graph[convert(-cnt)].push_back(convert(cnt));
        } else {
            int f = m[{i, a}] = ++cnt;
            rev[cnt] = {i, a};
            int s = m[{i, b}] = ++cnt;
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
            if (a == c) {
                graph[convert(m[{i, a}])].push_back(convert(-m[{j, c}]));
                graph[convert(m[{j, c}])].push_back(convert(-m[{i, a}]));
            } else {
                if (adj[a][c]) {
                    if (arr[i][adj[a][c]] != arr[j][adj[a][c]]) {
                        graph[convert(m[{i, a}])].push_back(convert(-m[{j, c}]));
                        graph[convert(m[{j, c}])].push_back(convert(-m[{i, a}]));
                    }
                }
            }

            if (a == d) {
                graph[convert(m[{i, a}])].push_back(convert(-m[{j, d}]));
                graph[convert(m[{j, d}])].push_back(convert(-m[{i, a}]));
            } else {
                if (adj[a][d]) {
                    if (arr[i][adj[a][d]] != arr[j][adj[a][d]]) {
                        graph[convert(m[{i, a}])].push_back(convert(-m[{j, d}]));
                        graph[convert(m[{j, d}])].push_back(convert(-m[{i, a}]));
                    }
                }
            }

            if (b == c) {
                graph[convert(m[{i, b}])].push_back(convert(-m[{j, c}]));
                graph[convert(m[{j, c}])].push_back(convert(-m[{i, b}]));
            } else {
                if (adj[b][c]) {
                    if (arr[i][adj[b][c]] != arr[j][adj[b][c]]) {
                        graph[convert(m[{i, b}])].push_back(convert(-m[{j, c}]));
                        graph[convert(m[{j, c}])].push_back(convert(-m[{i, b}]));
                    }
                }
            }


            if (b == d) {
                graph[convert(m[{i, b}])].push_back(convert(-m[{j, d}]));
                graph[convert(m[{j, d}])].push_back(convert(-m[{i, b}]));
            } else {
                if (adj[b][d]) {
                    if (arr[i][adj[b][d]] != arr[j][adj[b][d]]) {
                        graph[convert(m[{i, b}])].push_back(convert(-m[{j, d}]));
                        graph[convert(m[{j, d}])].push_back(convert(-m[{i, b}]));
                    }
                }
            }
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

    for (int i = 1; i <= N; i++) cout << out[i] << " ";
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