#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, M, sz;
vector<ll> val;
pair<pii, ll> arr[100005], _query[100005];
ll ans[100005];

void update(int pos, pii v, vector<pii> &seg) {
    for (seg[pos += sz] = v; pos > 0; pos >>= 1) seg[pos >> 1] = min(seg[pos], seg[pos ^ 1]);
    
}

pii query(int l, int r, vector<pii> &seg) {
    pii ret = {1e18, 1e18};
    r++;
    
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, seg[l++]);
        if (r & 1) ret = min(ret, seg[--r]);
    }
    
    return ret;
}

void solve() {
    cin >> N >> M;
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 0; i < N; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        arr[i] = {{x, y}, t};
        val.push_back(x), val.push_back(y);
    }
    sort(arr, arr + N, [&](pair<pii, ll> a, pair<pii, ll> b) {
        return a.first.second < b.first.second;
    });
    
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        _query[i] = {{s, e}, i};
        val.push_back(s), val.push_back(e);
        ans[i] = abs(s - e);
    }
    sort(_query, _query + M, [&](pair<pii, ll> a, pair<pii, ll> b) {
        return a.first.second < b.first.second;
    });
    
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    
    for (int i = 0; i < N; i++) {
        arr[i].first.first = lower_bound(val.begin(), val.end(), arr[i].first.first) - val.begin();
        arr[i].first.second = lower_bound(val.begin(), val.end(), arr[i].first.second) - val.begin();
    }
    
    for (int i = 0; i < M; i++) {
        _query[i].first.first = lower_bound(val.begin(), val.end(), _query[i].first.first) - val.begin();
        _query[i].first.second = lower_bound(val.begin(), val.end(), _query[i].first.second) - val.begin();
    }
    
    sz = val.size() + 5;
    
    vector<pii> lseg(3 * sz, {1e18, 1e18}), rseg(3 * sz, {1e18, 1e18});
    
    int idx = 0;
    for (int i = 0; i < M; i++) {
        ll x = _query[i].first.first, y = _query[i].first.second, id = _query[i].second;
        while (idx < N) {
            ll a = arr[idx].first.first, b = arr[idx].first.second, t = arr[idx].second;
            if (b <= y) {
                update(a, {(1e17 - val[a]) + (1e17 - val[b]) + t, idx}, lseg);
                update(a, {val[a] + (1e17 - val[b]) + t, idx}, rseg);
                idx++;
            } else break;
        }
        
        pii q1 = query(0, x, lseg), q2 = query(x, sz - 1, rseg);
        if (q1.second != 1e18) {
            ans[id] = min(ans[id], abs(val[x] - val[arr[q1.second].first.first]) +
                                   abs(val[y] - val[arr[q1.second].first.second]) +
                                   arr[q1.second].second);
        }
        if (q2.second != 1e18) {
            ans[id] = min(ans[id], abs(val[x] - val[arr[q2.second].first.first]) +
                                   abs(val[y] - val[arr[q2.second].first.second]) +
                                   arr[q2.second].second);
        }
    }
    
    lseg.clear(), rseg.clear();
    lseg.resize(3 * sz, {1e18, 1e18}), rseg.resize(3 * sz, {1e18, 1e18});
    
    idx = N - 1;
    for (int i = M - 1; i >= 0; i--) {
        ll x = _query[i].first.first, y = _query[i].first.second, id = _query[i].second;
        while (idx >= 0) {
            ll a = arr[idx].first.first, b = arr[idx].first.second, t = arr[idx].second;
            if (b >= y) {
                update(a, {(1e17 - val[a]) + val[b] + t, idx}, lseg);
                update(a, {val[a] + val[b] + t, idx}, rseg);
                idx--;
            } else break;
        }
        
        pii q1 = query(0, x, lseg), q2 = query(x, sz - 1, rseg);
        if (q1.second != 1e18) {
            ans[id] = min(ans[id], abs(val[x] - val[arr[q1.second].first.first]) +
                                   abs(val[y] - val[arr[q1.second].first.second]) +
                                   arr[q1.second].second);
        }
        if (q2.second != 1e18) {
            ans[id] = min(ans[id], abs(val[x] - val[arr[q2.second].first.first]) +
                                   abs(val[y] - val[arr[q2.second].first.second]) +
                                   arr[q2.second].second);
        }
    }
    
    for (int i = 0; i < M; i++) cout << ans[i] << '\n';
    
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