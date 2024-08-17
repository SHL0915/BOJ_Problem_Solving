#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, ll>;

int N, root;
pii ans;
string S;
vector<int> tree[100005];
int dp[100005];

void init() {
    for (int i = 1; i <= N; i++) tree[i].clear(), dp[i] = -1;
    ans = {0, 0};
    return;
}

int find_route(int node) {
    dp[node] = 1;
    priority_queue<int> pq;
    for (int next: tree[node]) {
        int v = find_route(next);
        if (S[node - 1] != S[next - 1]) pq.push(v);
    }

    int M1 = 0, M2 = 0;

    if (!pq.empty()) M1 = pq.top(), pq.pop();
    if (!pq.empty()) M2 = pq.top(), pq.pop();

    dp[node] += M1 + M2;

    return 1 + M1;
}

pii DFS(int node) {
    pii M = {0, 1};
    for (int next: tree[node]) {
        pii v = DFS(next);
        if (S[node - 1] == S[next - 1]) continue;

        if (v.first + M.first + 1 == ans.first) ans.second += (v.second * M.second);
        if (v.first == M.first) M.second += v.second;
        if (v.first > M.first) M = v;
    }

    if (ans.first == 1) ans.second++;
    M.first++;

    return M;
}

void solve() {
    cin >> N;
    cin >> S;

    init();

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        if (a) tree[a].push_back(i);
        else root = i;
    }

    find_route(root);
    for (int i = 1; i <= N; i++) ans.first = max(ans.first, dp[i]);

    DFS(root);

    cout << ans.first << " " << ans.second << '\n';

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