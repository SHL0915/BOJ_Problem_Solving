#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector<pii> Blue, Red;
int par[1005];

void init() {
    for (int i = 1; i <= N; i++) par[i] = i;
    return;
}

int find(int a) {
    if (a == par[a]) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[find(a)] = find(b);
    return;
}

void solve() {
    Blue.clear(), Red.clear();
    init();

    for (int i = 0; i < M; i++) {
        char color;
        cin >> color;
        int u, v;
        cin >> u >> v;
        if (color == 'R') Red.push_back({u, v});
        else Blue.push_back({u, v});
    }

    int cnt = 0, a = 0, b = 0;
    for (int i = 0; i < Red.size(); i++) {
        int u = Red[i].first, v = Red[i].second;
        if (find(u) == find(v)) continue;
        cnt++;
        merge(u, v);
    }

    for (int i = 0; i < Blue.size(); i++) {
        int u = Blue[i].first, v = Blue[i].second;
        if (find(u) == find(v)) continue;
        cnt++;
        merge(u, v);
        a++;
    }

    init();
    for (int i = 0; i < Blue.size(); i++) {
        int u = Blue[i].first, v = Blue[i].second;
        if (find(u) == find(v)) continue;
        b++;
        merge(u, v);
    }

    if (cnt < N - 1) cout << 0 << '\n';
    else {
        if (a <= K && K <= b) cout << 1 << '\n';
        else cout << 0 << '\n';
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
    while (1) {
        cin >> N >> M >> K;
        if (N == 0) break;
        solve();
    }
    return 0;
}