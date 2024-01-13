#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct edge {
    int u, v, idx, cost;
};

int N, M;
edge arr[3005], org[3005];
int mark[3005], par[3005];

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
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        arr[i] = {u, v, i, w};
        org[i] = arr[i];
    }

    sort(arr + 1, arr + M + 1, [&](edge a, edge b) {
        if (a.cost == b.cost) return a.idx < b.idx;
        else return a.cost < b.cost;
    });

    vector<pair<pii, int>> mst;
    init();
    for (int i = 1; i <= M; i++) {
        int u = arr[i].u, v = arr[i].v, idx = arr[i].idx, cost = arr[i].cost;
        if (find(u) == find(v)) continue;
        mark[idx] = 1;
        merge(u, v);
        mst.push_back({{u, v}, idx});
    }

    vector<pii> ans, temp;

    for (int i = 1; i <= N - 1; i++) {
        if (mark[i] == 1) {
            temp.push_back({org[i].u, org[i].v});
            continue;
        }
        init();
        for (pii j: temp) merge(j.first, j.second);
        for (int j = i + 1; j <= N - 1; j++) merge(org[j].u, org[j].v);

        for (auto j: mst) {
            if (find(j.first.first) != find(j.first.second)) {
                ans.push_back({i, j.second});
                temp.push_back(j.first);
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (pii i: ans) cout << i.first << " " << i.second << '\n';

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