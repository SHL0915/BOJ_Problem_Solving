#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

ll N, M, sz;
pair<pii, pii> arr[1600005];
pair<pii, int> v[1600005];
vector<ll> xpos;
ll dist[1600005];
set<pii> seg[1600005];

void add(int n, int s, int e, int idx, pii val) {
    if (idx > e || idx < s) return;
    if (s == e) {
        seg[n].insert(val);
        return;
    }
    int m = (s + e) >> 1;
    add(n * 2, s, m, idx, val);
    add(n * 2 + 1, m + 1, e, idx, val);
    seg[n].insert(val);
    return;
}

void del(int n, int s, int e, int idx, pii val) {
    if (idx > e || idx < s) return;
    if (s == e) {
        seg[n].erase(val);
        return;
    }
    int m = (s + e) >> 1;
    del(n * 2, s, m, idx, val);
    del(n * 2 + 1, m + 1, e, idx, val);
    seg[n].erase(val);
    return;
}

void query(int n, int s, int e, int l, int r, ll y, vector<int> &d) {
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        for (pii i: seg[n]) {
            if (i.first > y) break;
            d.push_back(i.second);
        }
        return;
    }
    int m = (s + e) >> 1;
    query(n * 2, s, m, l, r, y, d);
    query(n * 2 + 1, m + 1, e, l, r, y, d);
    return;
}

void Dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<>> pq;

    vector<int> d;

    for (int i = 0; i < M; i++) {
        int idx = v[i].second;
        if (arr[idx].first.second == 1) {
            dist[i] = arr[idx].second.second;
            pq.push({dist[i], i});
            d.push_back(i);
        }
    }

    for (int i: d) {
        ll x = v[i].first.first, y = v[i].first.second, idx = v[i].second;
        int pos = lower_bound(xpos.begin(), xpos.end(), x) - xpos.begin();
        del(1, 0, sz - 1, pos, {y, idx});
    }

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        ll now = t.second, val = t.first;
        int idx = v[now].second;
        ll x = arr[idx].second.first - arr[idx].first.first + 1, y = arr[idx].second.first + arr[idx].first.first + 1;

        d.clear();
        int pos = upper_bound(xpos.begin(), xpos.end(), x) - xpos.begin() - 1;

        query(1, 0, sz - 1, 0, pos, y, d);

        for (int i: d) {
            ll x = v[i].first.first, y = v[i].first.second, idx = v[i].second;
            int pos = lower_bound(xpos.begin(), xpos.end(), x) - xpos.begin();
            del(1, 0, sz - 1, pos, {y, idx});
            dist[i] = val + arr[idx].second.second;
            pq.push({dist[i], i});
        }
    }

    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll T, L, R, C;
        cin >> T >> L >> R >> C;
        ll x = L - T, y = L + T;
        arr[i] = {{T, L},
                  {R, C}};
        v[i] = {{x, y}, i};
        xpos.push_back(x);
        xpos.push_back(x + 1);
    }

    sz = xpos.size();

    sort(xpos.begin(), xpos.end());
    xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());

    for (int i = 0; i < M; i++) {
        ll x = v[i].first.first, y = v[i].first.second, idx = v[i].second;
        int pos = lower_bound(xpos.begin(), xpos.end(), x) - xpos.begin();
        add(1, 0, sz - 1, pos, {y, idx});
    }

    Dijkstra();

    ll ans = inf;
    for (int i = 0; i < M; i++) {
        int idx = v[i].second;
        if (arr[idx].second.first == N) ans = min(ans, dist[i]);
    }

    if (ans == inf) cout << -1;
    else cout << ans;

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