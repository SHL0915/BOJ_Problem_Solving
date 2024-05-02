#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int A[25], B[25];
vector<int> graph[1005];
int dp[20][(1 << 20)];

int DP(int now, int state) {
    if (now == N) return 1;
    int &ret = dp[now][state];
    if (ret != -1) return ret;
    ret = 0;
    
    for (int next: graph[A[now]]) {
        if (state & next) continue;
        ret |= DP(now + 1, state | next);
    }
    
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    for (int i = 0; i < (1 << M); i++) {
        int v = 0;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) v += B[j];
        }
        if (v <= 1000) graph[v].push_back(i);
    }
    
    memset(dp, -1, sizeof(dp));
    
    if (DP(0, 0)) cout << "YES";
    else cout << "NO";
    
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