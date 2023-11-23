#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int cnt[200005];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        vector<int> v(k);
        for (int j = 0; j < k; j++) cin >> v[j];
        cnt[v.front()]++;
        cnt[v.back()]++;
    }
    
    int tot = 0;
    for (int i = 1; i <= M; i++) {
        tot += cnt[i];
        if (tot >= N) {
            cout << i;
            return;
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