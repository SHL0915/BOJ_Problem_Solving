#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005], mark[100005], chk[100005];
int graph[100005];
vector<vector<int>> cycle;

void DFS(int node, int org) {
    if (mark[node]) {
        if (mark[node] == org) {
            vector<int> v;
            v.push_back(node);
            chk[node] = 1;
            node = graph[node];

            while (1) {
                if (chk[node]) break;
                chk[node] = 1;
                v.push_back(node);
                node = graph[node];
            }

            cycle.push_back(v);
            return;
        } else return;
    }
    mark[node] = org;
    
    DFS(graph[node], org);

    return;
}

void solve() {
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> graph[i] >> arr[i];
        ans += arr[i];
    }

    int id = 1;
    for (int i = 1; i <= N; i++) {
        if (mark[i] == 0) {
            DFS(i, id);
            id++;
        }
    }

    for (int i = 0; i < cycle.size(); i++) {
        sort(cycle[i].begin(), cycle[i].end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        ans -= arr[cycle[i].front()];
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