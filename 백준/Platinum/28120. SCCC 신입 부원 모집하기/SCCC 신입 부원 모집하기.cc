#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, X;
vector<pii> v;
vector<int> arr[16];
int dp[16][(1 << 16)];
int ans[16][(1 << 16)];
vector<int> aans[16];

int DP(int now, int state) {
    if (now == N) return 0;
    int &ret = dp[now][state];
    if (ret != -1) return ret;
    ret = 0;
    
    ret = DP(now + 1, state);
    
    int nnow = v[now].second;
    for (int a: arr[nnow]) {
        int l = a * X, r = l + X - 1;
        for (int j = l; j <= r; j++) {
            if (state & (1 << j)) continue;
            int nxt = 1 + DP(now + 1, state | (1 << j));
            if (ret < nxt) {
                ret = nxt;
                ans[now][state] = j;
            }
            break;
        }
    }
    
    return ret;
}

void solve() {
    cin >> N >> K >> X;
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a--;
            arr[i].push_back(a);
        }
    }
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    
    memset(dp, -1, sizeof(dp));
    memset(ans, -1, sizeof(ans));
    DP(0, 0);
    
    int now = 0;
    
    for (int i = 0; i < N; i++) {
        if (ans[i][now] == -1) continue;
        int nxt = ans[i][now];
        aans[nxt / X].push_back(v[i].second);
        now |= (1 << nxt);
    }
    
    for (int i = 0; i < K; i++) {
        cout << aans[i].size();
        for (int a: aans[i]) cout << " " << a;
        cout << '\n';
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