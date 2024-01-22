#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[100005];
int in_degree[100005];
int ans;

void topology() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!q.size()) break;
        int f = q.front();
        q.pop();
        ans++;
        for (int next: graph[f]) {
            if (--in_degree[next] == 0) q.push(next);
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        in_degree[a]++;
    }

    topology();

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