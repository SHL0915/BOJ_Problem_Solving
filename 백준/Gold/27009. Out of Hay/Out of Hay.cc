#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<pair<int, pii>> edge;
int par[2005];

void init() {
    for (int i = 1; i <= N; i++) par[i] = i;
}

int find(int a) {
    if (a == par[a]) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[find(a)] = find(b);
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    int l = 0, r = 1e9, ok = -1;
    while (l <= r) {
        int m = (l + r) / 2;

        init();
        for (int i = 0; i < M; i++) {
            if (edge[i].first > m) continue;
            merge(edge[i].second.first, edge[i].second.second);
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++) if (find(i) == find(1)) cnt++;

        if (cnt != N) l = m + 1;
        else ok = m, r = m - 1;
    }

    cout << ok;

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