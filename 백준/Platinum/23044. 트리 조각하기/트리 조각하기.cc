#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
int arr[200005], dist[200005], chk[200005];
vector<int> tree[200005];
queue<int> q;

void BFS() {
    int now = q.front();
    q.pop();
    for (int next: tree[now]) {
        if (dist[next] == INF) {
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    return;
}

void check() {
    int now = q.front();
    q.pop();
    for (int next: tree[now]) {
        if (chk[next] == INF) {
            chk[next] = chk[now] + 1;
            q.push(next);
        }
    }
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int l = 1, r = N;
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        memset(dist, 0x3f, sizeof(dist));
        for (int i = 1; i <= N; i++) if (!arr[i]) q.push(i), dist[i] = 0;
        while (q.size()) BFS();

        memset(chk, 0x3f, sizeof(chk));
        for (int i = 1; i <= N; i++) if (dist[i] >= m) q.push(i), chk[i] = 0;

        while (q.size()) check();

        int flag = 0;
        for (int i = 1; i <= N; i++) {
            if (arr[i] && chk[i] >= m) flag = 1;
        }

        if (flag) r = m - 1;
        else ans = m, l = m + 1;
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