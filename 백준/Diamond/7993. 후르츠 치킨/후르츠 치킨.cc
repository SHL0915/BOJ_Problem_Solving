#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, W, Z, P, A;
vector<int> tree[1000005];
int dp[1000005];
set<int> s;
vector<int> dA, dB;

void findA(int node, int par) {
    if (node >= N - Z + 1) dp[node]++;
    for (int next: tree[node]) {
        if (next == par) continue;
        findA(next, node);
        dp[node] += dp[next];
    }
    if (A == -1 && dp[node] == Z && node < N - Z + 1) A = node;
    return;
}

void DFS(int node, int par, int lv) {
    if (node >= N - Z + 1) dA.push_back(lv);
    if (s.count(node)) dB.push_back(lv);
    for (int next: tree[node]) {
        if (next == par) continue;
        DFS(next, node, lv + 1);
    }
    return;
}

void solve() {
    cin >> N >> W >> Z;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    A = -1;
    findA(1, 1);
    
    cin >> P;
    
    for (int i = 0; i < P; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    
    DFS(A, A, 0);
    
    sort(dA.begin(), dA.end());
    sort(dB.begin(), dB.end());
    
    for (int i = 1; i < dB.size(); i++) {
        if (dB[i] <= dB[i - 1]) dB[i] = dB[i - 1] + 1;
    }
    
    cout << dB.back() + dA.front();
    
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