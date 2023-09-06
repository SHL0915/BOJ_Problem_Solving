#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct line {
    int l, r, idx;
};

int N, Q;
line arr[150005];
pii seg[800005];
int rev[150005];
int par[150005][25];
vector<ll> v;

void update(int pos, pii val) {
    for (seg[pos += 2 * N] = max(seg[pos], val); pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

pii query(ll l, ll r) {
    r++;
    pii ret = {-INF, -INF};
    for (l += 2 * N, r += 2 * N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

int q(int a, int b) {
    if (arr[a].l > arr[b].l) swap(a, b);
    if (arr[a].r >= arr[b].l) return 1;
    if (arr[par[a][20]].r < arr[b].l) return -1;
    int ret = 1;
    for (int i = 20; i >= 0; i--) {
        int now = par[a][i];
        if (arr[now].r >= arr[b].l) continue;
        ret += (1 << i);
        a = now;
    }
    return ret + 1;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        arr[i] = {a, b, i};
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    sort(arr + 1, arr + N + 1, [&](line a, line b) {
        return a.r < b.r;
    });
    
    for(int i = 1; i <= N; i++) {
        int l = lower_bound(v.begin(), v.end(), arr[i].l) - v.begin();
        int r = lower_bound(v.begin(), v.end(), arr[i].r) - v.begin();
        update(l, {r, i});
    }
    
    for (int i = 1; i <= N; i++) {
        int r = lower_bound(v.begin(), v.end(), arr[i].r) - v.begin();
        pii q = query(0, r);
        rev[arr[i].idx] = i;
        par[i][0] = q.second;
    }
    
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= N; j++) par[j][i] = par[par[j][i - 1]][i - 1];
    }
    
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a = rev[a], b = rev[b];
        cout << q(a, b) << '\n';
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