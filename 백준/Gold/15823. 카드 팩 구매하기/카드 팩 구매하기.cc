#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[100005];
int pos[500005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    int l = 1, r = N;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        memset(pos, -1, sizeof(pos));
        
        int idx = 0, cnt = 0, s = 0;
        
        for (; idx < N; idx++) {
            int now = arr[idx];
            if (pos[now] == -1) {
                pos[now] = idx;
                if (idx - s + 1 == mid) {
                    cnt++;
                    for (s; s <= idx; s++) pos[arr[s]] = -1;
                }
            } else {
                for (s; s <= pos[now]; s++) pos[arr[s]] = -1;
                pos[now] = idx;
                if (idx - s + 1 == mid) {
                    cnt++;
                    for (s; s <= idx; s++) pos[arr[s]] = -1;
                }
            }
        }
        
        if (cnt >= M) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    
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