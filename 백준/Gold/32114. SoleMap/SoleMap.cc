#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int N, M;
ll arr[500005];
ll psum[500005];

ll f(int now) {
    ll x = psum[now], w = arr[now];

    ll m = x % w;
    
    ll ret = (x / w) * (x / w) * (w - m);
    ret += (x / w + 1) * (x / w + 1) * m;

    return ret;
}

void solve() {
    cin >> N >> M;
    for(int i = 1; i <= N - 1; i++) cin >> arr[i];
    for(int i = 0; i < M; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        psum[u] += x;
        psum[v] -= x;
    }

    for(int i = 1; i <= N; i++) psum[i] += psum[i - 1];

    for(int i = 1; i <= N - 1; i++) cout << f(i) << '\n';

    return;
}


int main(void) {
    ios::sync_with_stdio(false);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;
}