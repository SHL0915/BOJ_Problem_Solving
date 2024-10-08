#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, M, Q, mod, S;
pii arr[1005][1005];
int vst[1005][1005], is_cycle[1005][1005];
int kth[3000005], before_k[3000005];

void find_cycle(int a, int b, ll k) {
    if (is_cycle[a][b]) return;
    is_cycle[a][b] = 1;
    string now = to_string(b);
    for (int i = 0; i < now.size(); i++) kth[k] = now[i] - '0', k++;
    
    mod = max(mod, k - 1);
    find_cycle(arr[a][b].first, arr[a][b].second, k);
    
    return;
}

void DFS(int a, int b, ll k) {
    if (vst[a][b]) {
        find_cycle(a, b, 1);
        return;
    }
    vst[a][b] = 1;
    string now = to_string(b);
    for (int i = 0; i < now.size(); i++) before_k[k] = now[i] - '0', k++;
    S = max(S, k - 1);
    DFS(arr[a][b].first, arr[a][b].second, k);
}

void solve() {
    cin >> Q >> M;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = {j, (i + j) % M};
        }
    }
    
    before_k[1] = 1;
    DFS(1, 1, 2);
    
    while (Q--) {
        cin >> N;
        
        if (N <= S) cout << before_k[N] << '\n';
        else {
            N -= S;
            N--;
            N %= mod;
            N++;
            cout << kth[N] << '\n';
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