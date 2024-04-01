#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 500005;

int N;
pii seg[500005 * 2];
int dp[500005], pre[500005], arr[500005];

void update(int pos, pii v) {
    pos += sz;
    seg[pos] = max(seg[pos], v);
    for (; pos > 0; pos >>= 1) seg[pos] = max(seg[pos], v);
    return;
}

pii query(int l, int r) {
    r++;
    pii ret = {-1, -1};
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> N;
    set<int> idx;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
        idx.insert(a);
    }
    
    for (int i: idx) {
        pii q = query(0, arr[i] - 1);
        dp[i] = q.first + 1;
        pre[i] = q.second;
        update(arr[i], {dp[i], i});
    }
    
    pii ans = {0, 0};
    for (int i: idx) ans = max(ans, {dp[i], i});
    
    int now = ans.second;
    set<int> s;
    vector<int> v;
    
    while (ans.first--) s.insert(now), now = pre[now];
    
    cout << N - s.size() << '\n';
    for (int i: idx) if (!s.count(i)) cout << i << '\n';
    
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