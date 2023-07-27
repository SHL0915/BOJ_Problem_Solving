#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, P, D;
pii arr[10];
vector<pair<pii, int>> edge;
int pre[(1 << 20)][2];
int dp[(1 << 20)][2];

int cnt(int state, int idx) {
    int a = state & (1 << (idx * 2));
    int b = state & (1 << (idx * 2 + 1));
    
    if (a) a = 1;
    if (b) b = 2;
    
    return a + b;
}

int convert(int state, int idx, int val) {
    int a = (val & 1) != 0;
    int b = (val & 2) != 0;
    
    state |= (1 << (idx * 2));
    if (a == 0) state ^= (1 << (idx * 2));
    
    state |= (1 << (idx * 2 + 1));
    if (b == 0) state ^= (1 << (idx * 2 + 1));
    
    return state;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    cin >> P >> D;
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int dist = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
            if (dist >= D) edge.push_back({{i, j}, dist});
        }
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for (int i = 1; i <= edge.size(); i++) {
        memset(pre, -1, sizeof(pre));
        int a = edge[i - 1].first.first, b = edge[i - 1].first.second;
        int d = edge[i - 1].second;
        for (int j = 0; j < (1 << (2 * N)); j++) {
            if (dp[j][0] == -1) continue;
            if (pre[j][0] == -1 || pre[j][0] > dp[j][0]) {
                pre[j][0] = dp[j][0];
                pre[j][1] = dp[j][1];
            } else if (pre[j][0] != -1 && pre[j][0] == dp[j][0])
                pre[j][1] = min(pre[j][1], dp[j][1]);
            
            int acnt = cnt(j, a);
            int bcnt = cnt(j, b);
            
            if (acnt < P && bcnt < P) {
                int next = convert(j, a, acnt + 1);
                next = convert(next, b, bcnt + 1);
                if (pre[next][0] == -1 || pre[next][0] > dp[j][0] + 1) {
                    pre[next][0] = dp[j][0] + 1;
                    pre[next][1] = dp[j][1] + d;
                } else if (pre[next][0] != -1 && pre[next][0] == dp[next][0] + 1)
                    pre[next][1] = min(pre[next][1], dp[j][1] + d);
            }
        }
        
        swap(pre, dp);
    }
    
    pii ans = {-INF, INF};
    
    for (int i = 0; i < (1 << (2 * N)); i++) {
        if (dp[i][0] == -1) continue;
        
        if (dp[i][0] > ans.first) ans = {dp[i][0], dp[i][1]};
        if (dp[i][0] == ans.first) ans.second = min(ans.second, dp[i][1]);
    }
    
    cout << ans.first << " " << ans.second;
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