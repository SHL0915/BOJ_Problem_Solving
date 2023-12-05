#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, K;
vector<int> graph[200005];
vector<int> arr[200005];
int mark[200005], par[200005];

int find(int a) {
    if (a == par[a]) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[find(a)] = find(b);
    return;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) par[i] = i;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        arr[1].push_back(a);
        mark[a] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int a: arr[i - 1]) {
            for (int b: graph[a]) {
                if (mark[b]) continue;
                mark[b] = 1;
                arr[i].push_back(b);
            }
        }
    }
    
    for (int i = N; i >= 1; i--) {
        int flag = 0;
        for (int a: arr[i]) {
            mark[a] = 0;
            for (int b: graph[a]) {
                if (mark[b]) continue;
                else {
                    if (find(a) == find(b)) flag = 1;
                    else merge(a, b);
                    
                }
            }
        }
        if (flag) {
            cout << i;
            return;
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