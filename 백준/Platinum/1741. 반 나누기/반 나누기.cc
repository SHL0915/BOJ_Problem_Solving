#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[100005];
int parent[100005], sz[100005];

int find(int a) {
    if (parent[a] == a) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (a > b) {
        parent[a] = b;
        sz[b] += sz[a];
    } else {
        parent[b] = a;
        sz[a] += sz[b];
    }
    return;
}


void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i, sz[i] = 1;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
    
    int idx = 1;
    for (int i = 2; i <= N; i++) {
        if (graph[i].size() < graph[idx].size()) swap(i, idx);
    }
    
    vector<int> A;
    for (int i = 1; i <= N; i++) {
        if (!binary_search(graph[idx].begin(), graph[idx].end(), i)) {
            merge(i, idx);
            A.push_back(i);
        }
    }
    
    for (int a: graph[idx]) {
        int flag = 0;
        for (int b: A) {
            if (!binary_search(graph[b].begin(), graph[b].end(), a)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            A.push_back(a);
            merge(idx, a);
        }
    }
    
    for (int a: graph[idx]) {
        for (int b: graph[idx]) {
            if (!binary_search(graph[a].begin(), graph[a].end(), b)) merge(a, b);
        }
    }
    
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (find(i) == i) ans.push_back(sz[find(i)]);
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << " ";
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