#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, K, D;
vector<int> v[100005];
pii arr[100005];
int cnt[35];

void solve() {
    cin >> N >> K >> D;
    for (int i = 0; i < N; i++) {
        int M, d;
        cin >> M >> d;
        while (M--) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
        arr[i] = {d, i};
    }
    
    sort(arr, arr + N);
    
    ll ans = 0;
    int ptr = 0;
    for (int i = 0; i < N; i++) {
        while (ptr < N) {
            if (arr[ptr].first - arr[i].first <= D) {
                for (int a: v[arr[ptr].second]) cnt[a]++;
                ptr++;
            } else break;
        }
        
        ll ccnt = 0;
        for (int j = 0; j <= K; j++) {
            if (!cnt[j] || cnt[j] == ptr - i) continue;
            else ccnt++;
        }
        
        ans = max(ans, ccnt * (ptr - i));
        for (int a: v[arr[i].second]) cnt[a]--;
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