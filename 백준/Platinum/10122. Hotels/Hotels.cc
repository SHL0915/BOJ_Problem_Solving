#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, ans;
vector<int> tree[5005];
ll cnt[5005][5005];

void count(int node, int par) {
    cnt[node][0]++;
    for (int next: tree[node]) {
        if (next == par) continue;
        count(next, node);
        for (int i = 0; i <= N; i++) cnt[node][i + 1] += cnt[next][i];
    }
    return;
}

void DFS(int node, int par, vector<ll> pcnt) {
    for (int k = 1; k <= N; k++) {
        ll ccnt[4] = {0};
        ccnt[1] = pcnt[k];
        for (int next: tree[node]) {
            if (next == par) continue;
            ccnt[3] += ccnt[2] * cnt[next][k - 1];
            ccnt[2] += ccnt[1] * cnt[next][k - 1];
            ccnt[1] += cnt[next][k - 1];
        }
        ans += ccnt[3];
    }

    vector<ll> nxt(N + 5, 0);
    for (int k = 1; k <= N; k++) nxt[k] += pcnt[k - 1];
    for (int k = 1; k <= N; k++) nxt[k] += cnt[node][k - 1];


    for (int next: tree[node]) {
        if (next == par) continue;
        vector<ll> v = nxt;
        for (int k = 2; k <= N; k++) v[k] -= cnt[next][k - 2];
        DFS(next, node, v);
    }

    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    count(1, 1);
    vector<ll> v(N + 5, 0);

    DFS(1, 1, v);

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