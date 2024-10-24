#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1005];
vector<int> graph[1005];
vector<pii> ans;

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), [&](int a, int b) {
            return arr[a] > arr[b];
        });
        if (graph[i].size()) ans.push_back({i, graph[i][0]});
        for (int j = 1; j < graph[i].size(); j++) ans.push_back({graph[i][j - 1], graph[i][j]});
    }

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