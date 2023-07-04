#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[400005];
vector<int> graph[400005];
int in_degree[400005];
vector<int> ans;

void Topology();

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            graph[i].push_back(a);
            in_degree[a]++;
        }
    }

    Topology();

    reverse(ans.begin(), ans.end());

    int ret = 0;
    for(int i = 0; i < ans.size(); i++) {
        ret = max(ret, arr[ans[i]] + i);
    }

    cout << ret;
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

void Topology() {
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 1; i <= N; i++) if (in_degree[i] == 0) pq.push({arr[i], i});

    for (int i = 1; i <= N; i++) {
        pii t = pq.top();
        pq.pop();
        ans.push_back(t.second);

        for (int j = 0; j < graph[t.second].size(); j++) {
            int next = graph[t.second][j];
            if (--in_degree[next] == 0) pq.push({arr[next], next});
        }
    }

    return;
}