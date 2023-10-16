#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f;

int N, M;
vector<int> graph[200005];
int vst[200005];
queue<int> q;

void BFS() {
    int now = q.front();
    q.pop();

    for (int next: graph[now]) {
        if (vst[next] != INF) continue;
        vst[next] = vst[now] + 1;
        q.push(next);
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(vst, INF, sizeof(vst));
    q.push(1);
    vst[1] = 0;
    while (q.size()) BFS();

    vector<int> cnt(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (vst[i] != INF) cnt[vst[i]]++;
    }

    ll ans = 1;
    for (int i = 0; i <= N; i++) {
        ans *= (cnt[i] + 1);
        ans %= mod;
    }

    cout << (ans - 1 + mod) % mod;

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