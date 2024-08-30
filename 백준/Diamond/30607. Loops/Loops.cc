#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int ans[505][505], in_degree[505 * 505];
string arr[505];
map<int, int> chk[505 * 505];
vector<int> graph[505 * 505];

int convert(int y, int x) {
    return y * M + x;
}

pii reconvert(int k) {
    return {k / M, k % M};
}

void toposort() {
    queue<int> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (in_degree[convert(i, j)] == 0) q.push(convert(i, j));
        }
    }

    for (int i = 1; i <= N * M; i++) {
        int f = q.front();
        q.pop();
        pii pos = reconvert(f);
        ans[pos.first][pos.second] = i;
        for (int next: graph[f]) {
            if (--in_degree[next] == 0) q.push(next);
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < M - 1; i++) {
        chk[convert(0, i)][convert(0, i + 1)] = 1;
        graph[convert(0, i)].push_back(convert(0, i + 1));
        in_degree[convert(0, i + 1)]++;
    }

    for (int i = 0; i < N - 1; i++) {
        chk[convert(i, 0)][convert(i + 1, 0)] = 1;
        graph[convert(i, 0)].push_back(convert(i + 1, 0));
        in_degree[convert(i + 1, 0)]++;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            int now = arr[i - 1][j - 1] - '0';

            int a = convert(i - 1, j - 1), b = convert(i - 1, j), c = convert(i, j - 1), d = convert(i, j);

            int u = chk[a][b];
            int l = chk[a][c];

            if (!u && !l) {
                if (now == 1) {
                    graph[d].push_back(b), in_degree[b]++;
                    graph[d].push_back(c), in_degree[c]++;
                    graph[c].push_back(b), in_degree[b]++;
                    graph[d].push_back(a), in_degree[a]++;
                    chk[b][d] = 0;
                    chk[c][d] = 0;
                } else if (now == 2) {
                    graph[d].push_back(b), in_degree[b]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[c].push_back(b), in_degree[b]++;
                    graph[d].push_back(a), in_degree[a]++;
                    chk[b][d] = 0;
                    chk[c][d] = 1;
                } else {
                    graph[d].push_back(b), in_degree[b]++;
                    graph[d].push_back(c), in_degree[c]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[d].push_back(a), in_degree[a]++;
                    chk[b][d] = 0;
                    chk[c][d] = 0;
                }
            } else if (!u) {
                if (now == 1) {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[d].push_back(c), in_degree[c]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 1;
                    chk[c][d] = 0;
                } else if (now == 2) {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 1;
                    chk[c][d] = 1;
                } else {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[d].push_back(c), in_degree[c]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[d].push_back(a), in_degree[a]++;
                    chk[b][d] = 1;
                    chk[c][d] = 0;
                }
            } else if (!l) {
                if (now == 1) {
                    graph[d].push_back(b), in_degree[b]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[c].push_back(b), in_degree[b]++;
                    graph[d].push_back(a), in_degree[a]++;
                    chk[b][d] = 0;
                    chk[c][d] = 1;
                } else if (now == 2) {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[c].push_back(b), in_degree[b]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 1;
                    chk[c][d] = 1;
                } else {
                    graph[d].push_back(b), in_degree[b]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 0;
                    chk[c][d] = 1;
                }
            } else {
                if (now == 1) {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 1;
                    chk[c][d] = 1;
                } else if (now == 2) {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[d].push_back(c), in_degree[c]++;
                    graph[b].push_back(c), in_degree[c]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 1;
                    chk[c][d] = 0;
                } else {
                    graph[b].push_back(d), in_degree[d]++;
                    graph[c].push_back(d), in_degree[d]++;
                    graph[c].push_back(b), in_degree[b]++;
                    graph[a].push_back(d), in_degree[d]++;
                    chk[b][d] = 1;
                    chk[c][d] = 1;
                }
            }
        }
    }

    toposort();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cout << ans[i][j] << " ";
        cout << '\n';
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