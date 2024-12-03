#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
string arr[100005];
map<string, int> idx;
vector<int> tree[100005];
string ans;

void DFS(int node, int par, int destination) {
    ans += arr[node][0];
    if (node == destination) {
        cout << ans << '\n';
        ans.pop_back();
        return;
    }
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node, destination);
    }
    ans.pop_back();
}

void solve() {
    cin >> N >> Q;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        if (!idx.count(a)) {
            idx[a] = ++cnt;
            arr[cnt] = a;
        }
        if (!idx.count(b)) {
            idx[b] = ++cnt;
            arr[cnt] = b;
        }
        tree[idx[a]].push_back(idx[b]);
        tree[idx[b]].push_back(idx[a]);
    }

    while (Q--) {
        string a, b;
        cin >> a >> b;
        ans = "";
        DFS(idx[a], -1, idx[b]);
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