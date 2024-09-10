#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int par[100005], ok[100005];

int find(int a) {
    if (par[a] == a) return par[a];
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    par[find(a)] = find(b);
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) par[i] = i;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!ok[find(i)]) {
            ok[find(i)] = 1;
            cnt++;
        }
    }
    
    int ans = 0;
    ans += cnt - 1;
    
    ans += (M + (cnt - 1)) - (N - 1);
    
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