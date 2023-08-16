#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int parent[200005];
pair<int, pii> query[200005];
ll ans[200005];
vector<ll> psum[200005];
pii pos[200005];
deque<int> v[200005];

int find(int a) {
    if (a == parent[a]) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    parent[find(b)] = find(a);
    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= 200000; i++) parent[i] = i;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        int f;
        cin >> f;
        v[f].push_back(f);
        for (int j = 1; j < k; j++) {
            int a;
            cin >> a;
            v[f].push_back(a);
            merge(f, a);
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        query[i] = {a, {b, c}};
        if (a == 1) {
            if (find(b) == find(c)) ans[i] = 1;
            else {
                ans[i] = 0;
                if (v[find(b)].size() < v[find(c)].size()) {
                    swap(v[find(b)], v[find(c)]);
                    while (v[find(c)].size()) {
                        int bb = v[find(c)].back();
                        v[find(c)].pop_back();
                        v[find(b)].push_front(bb);
                    }
                } else {
                    while (v[find(c)].size()) {
                        int bb = v[find(c)].front();
                        v[find(c)].pop_front();
                        v[find(b)].push_back(bb);
                    }
                }
                merge(b, c);
            }
        } else {
            if (find(b) != find(c)) ans[i] = -1;
            else ans[i] = 2;
        }
    }

    for (int i = 1; i <= 200000; i++) {
        if (v[i].size() == 0) continue;
        psum[i].resize(v[i].size() + 5, 0);
        for (int j = 0; j < v[i].size(); j++) {
            int now = v[i][j];
            pos[now] = {i, j + 1};
            psum[i][j + 1] = psum[i][j] + now;
        }
    }

    for (int i = 0; i < Q; i++) {
        if (ans[i] == 1) cout << "NO\n";
        else if (ans[i] == 0) cout << "YES\n";
        else if (ans[i] == -1) cout << ans[i] << '\n';
        else {
            int a = query[i].second.first, b = query[i].second.second;
            int l = min(pos[a].second, pos[b].second), r = max(pos[a].second, pos[b].second);

            cout << psum[pos[a].first][r] - psum[pos[a].first][l - 1] << '\n';
        }
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