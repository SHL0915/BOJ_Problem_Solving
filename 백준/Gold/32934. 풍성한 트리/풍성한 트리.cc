#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> tree[200005];
int dist[200005];
queue<int> q;

void BFS() {
    int now = q.front();
    q.pop();
    for (int next: tree[now]) {
        if (dist[next] != -1) continue;
        dist[next] = dist[now] + 1;
        q.push(next);
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int ok = 0;
    for (int i = 1; i <= N; i++) {
        if (tree[i].size() != 1 && tree[i].size() != 3) ok = 1;
    }

    if (ok) {
        cout << -1;
        return;
    }

    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= N; i++) {
        if (tree[i].size() == 1) {
            dist[i] = 0;
            q.push(i);
        }
    }

    while (q.size()) BFS();

    int d = 0;
    for (int i = 1; i <= N; i++) d = max(d, dist[i]);

    if (!d) {
        cout << -1;
        return;
    }

    vector<int> cand;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == d) cand.push_back(i);
    }

    vector<int> ans;
    for (int i: cand) {
        int a = dist[tree[i].front()];
        int flag = 0;
        for (int next: tree[i]) {
            if (dist[next] != a) flag = 1;
        }
        if (!flag) ans.push_back(i);
    }

    if (ans.size() == 0) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i: ans) cout << i << " ";
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