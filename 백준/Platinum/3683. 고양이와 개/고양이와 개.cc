#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int C, D, V;
vector<int> graph[505];
vector<pii> A[105], B[105];
int AA[505], BB[505], mark[505];

int DFS(int node) {
    mark[node] = 1;
    for (int next: graph[node]) {
        if (BB[next] == -1) {
            AA[node] = next;
            BB[next] = node;
            return 1;
        }
    }

    for (int next: graph[node]) {
        if (mark[BB[next]] == 0 && DFS(BB[next])) {
            AA[node] = next;
            BB[next] = node;
            return 1;
        }
    }

    return 0;
}

void solve() {
    cin >> C >> D >> V;

    for (int i = 0; i < 505; i++) graph[i].clear();
    for (int i = 0; i < 105; i++) A[i].clear(), B[i].clear();

    for (int i = 0; i < V; i++) {
        string s, t;
        cin >> s >> t;
        int a = 0, b = 0;
        for (int j = 1; j < s.length(); j++) {
            a *= 10;
            a += s[j] - '0';
        }
        for (int j = 1; j < t.length(); j++) {
            b *= 10;
            b += t[j] - '0';
        }
        if (s[0] == 'C') A[a].push_back({i, b});
        else B[a].push_back({i, b});
    }

    for (int i = 1; i < 105; i++) {
        for (pii j: A[i]) {
            int now = j.first, k = j.second;
            for (pii l: B[k]) graph[now].push_back(l.first);
        }
        for (pii j: B[i]) {
            int now = j.first, k = j.second;
            for (pii l: A[k]) graph[l.first].push_back(now);
        }
    }

    memset(AA, -1, sizeof(AA));
    memset(BB, -1, sizeof(BB));

    int cnt = 0;
    for (int i = 0; i < V; i++) {
        if (AA[i] == -1) {
            memset(mark, 0, sizeof(mark));
            cnt += DFS(i);
        }
    }

    cout << V - cnt << '\n';

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}