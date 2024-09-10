#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll arr[300005], sum[600005], cnt[600005];

void DFS(int node) {
    if (node > N) return;
    sum[node] += arr[node];
    DFS(node * 2);
    DFS(node * 2 + 1);
    sum[node] += sum[node * 2];
    sum[node] += sum[node * 2 + 1];
    if (!sum[node * 2]) cnt[node] = 1;
    cnt[node] += cnt[node * 2];
    cnt[node] += cnt[node * 2 + 1];
    return;
}

void solve() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) cin >> arr[i];
    DFS(1);
    
    for (int i = 1; i <= N; i++) {
        ll l = 0, r = sum[i], ok = -1;
        while (l <= r) {
            ll m = (l + r) / 2;
            ll tot = 0;
            
            int now = i;
            tot += cnt[now] * m;
            
            while (now != 1) {
                tot += max(0LL, cnt[now ^ 1] * m - sum[now ^ 1]);
                now /= 2;
            }
            
            if (tot >= sum[i]) {
                r = m - 1;
                ok = m;
            } else l = m + 1;
        }
        
        cout << ok << " ";
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