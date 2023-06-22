#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, double>;

int N, Q, cnt;
map<string, int> id;
double adj[205][205];

void solve() {
    cin >> N >> Q;
    
    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            if (i == j) adj[i][j] = 1;
            else adj[i][j] = -1;
        }
    }
    
    for (int i = 0; i < N; i++) {
        double a, b;
        string s, t;
        char equal;
        cin >> a >> s >> equal >> b >> t;
        
        if (id[s] == 0) id[s] = ++cnt;
        if (id[t] == 0) id[t] = ++cnt;
        
        adj[id[s]][id[t]] = b;
        adj[id[t]][id[s]] = 1 / b;
    }
    
    for(int k = 1; k <= cnt; k++) {
        for(int i = 1; i <= cnt; i++) {
            for(int j = 1; j <= cnt; j++) {
                if(adj[i][j] != -1) continue;
                if(adj[i][k] != -1 && adj[k][j] != -1) adj[i][j] = adj[i][k] * adj[k][j];
            }
        }
    }
    
    
    for (int i = 0; i < Q; i++) {
        double a;
        string s, t, u;
        cin >> a >> s >> t >> u;
        int from = id[s], to = id[u];
        
        if(adj[from][to] == -1) cout << "impossible\n";
        else cout << adj[from][to] * a << '\n';
    }
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}