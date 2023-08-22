#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
int color[100005];
vector<int> graph[100005];
map<pii, int> m;
map<int, int> c[100005];
int cnt[100005];

void tree_dp(int node, int par) {
    c[node][color[node]]++;
    if (cnt[color[node]] == 1) c[node].erase(color[node]);

    for (int next: graph[node]) {
        if (next == par) continue;
        tree_dp(next, node);

        if (c[next].size() > c[node].size()) {
            for (auto e: c[node]) {
                int co = e.first, val = e.second;
                c[next][co] += val;
                if (cnt[co] == c[next][co]) c[next].erase(co);
            }
            swap(c[node], c[next]);
        } else {
            for (auto e: c[next]) {
                int co = e.first, val = e.second;
                c[node][co] += val;
                if (cnt[co] == c[node][co]) c[node].erase(co);
            }
        }
    }

    if (node != 1 && c[node].size() == 0) ans++;
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N - 2; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        color[i] = d;
        cnt[d]++;

        if (m.count({a, b})) {
            graph[m[{a, b}]].push_back(i);
            graph[i].push_back(m[{a, b}]);
        } else m[{a, b}] = i;

        if (m.count({a, c})) {
            graph[m[{a, c}]].push_back(i);
            graph[i].push_back(m[{a, c}]);
        } else m[{a, c}] = i;

        if (m.count({b, c})) {
            graph[m[{b, c}]].push_back(i);
            graph[i].push_back(m[{b, c}]);
        } else m[{b, c}] = i;
    }

    tree_dp(1, 1);

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