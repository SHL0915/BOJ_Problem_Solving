#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, K;
vector <pair<int, int>> tree[100001];
int parent[100001][21];
int level[100001];
int m_val[100001][21];
int M_val[100001][21];

void pre(int node, int par, int lv, int val);
int LCA(int a, int b);
int m_query(int a, int b);
int M_query(int a, int b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }
    memset(m_val, INF, sizeof(m_val));
    memset(M_val, -1, sizeof(M_val));
    pre(1, 0, 1, 0);
    cin >> K;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        cout << min(m_query(lca, a), m_query(lca, b)) << " " << max(M_query(lca, a), M_query(lca, b)) << '\n';
    }
    return 0;
}

void pre(int node, int par, int lv, int val) {
    level[node] = lv;
    parent[node][0] = par;
    m_val[node][0] = val;
    M_val[node][0] = val;
    for (int i = 1; i < 21; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
        m_val[node][i] = min(m_val[node][i - 1], m_val[parent[node][i - 1]][i - 1]);
        M_val[node][i] = max(M_val[node][i - 1], M_val[parent[node][i - 1]][i - 1]);
    }
    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        if (next == par) continue;
        pre(next, node, lv + 1, tree[node][i].second);
    }
    return;
}

int LCA(int a, int b) {
    if (a == 1 || b == 1) return 1;
    if (level[a] < level[b]) swap(a, b);
    if (level[a] != level[b]) {
        for (int i = 20; i >= 0; i--) {
            if (level[parent[a][i]] >= level[b]) a = parent[a][i];
        }
    }
    int ret = a;
    if (a != b) {
        for (int i = 20; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
            ret = parent[a][i];
        }
    }
    return ret;
}

int m_query(int a, int b) {
    if (a == b) return INF;
    int ret = INF;
    for (int i = 20; i >= 0; i--) {
        if (level[parent[b][i]] >= level[a]) {
            ret = min(ret, m_val[b][i]);
            b = parent[b][i];
        }
    }
    return ret;
}

int M_query(int a, int b) {
    if (a == b) return 0;
    int ret = -1;
    for (int i = 20; i >= 0; i--) {
        if (level[parent[b][i]] >= level[a]) {
            ret = max(ret, M_val[b][i]);
            b = parent[b][i];
        }
    }
    return ret;
}