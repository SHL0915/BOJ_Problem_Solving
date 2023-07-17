#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll INF = 1e15;
const double tiny = 1e-7;

struct line {
    double a, b;
    double s;
    int idx;

    line(double a, double b, double s, int idx) : a(a), b(b), s(s), idx(idx) {};

    bool operator<(const line &cmp) const {
        if (abs(a - cmp.a) <= tiny) return b < cmp.b;
        return a < cmp.a;
    }
};

ll m, M, N, Q;
vector<pii> arr;
vector<line> v, L;

double slope(ll a, ll b) {
    return (double) (b - a) / M;
}

double intersect(line &a, line &b) {
    return (double) (a.b - b.b) / (a.a - b.a);
}

void add_line(line &l) {

    if (L.size() == 0) {
        L.push_back(l);
        return;
    }

    while (L.size()) {
        line t = L.back();

        if (abs(t.a - l.a) <= tiny) return;
        double x = intersect(t, l);
        if (x <= t.s) L.pop_back();
        else break;
    }

    if (L.size() == 0) L.push_back(l);
    else {
        l.s = intersect(L.back(), l);
        L.push_back(l);
    }

    return;
}

int query(double x) {
    int l = 0, r = L.size() - 1;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (L[mid].s <= x + tiny) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return L[ans].idx;
}


void solve() {
    cin >> M >> m;
    ll sub = m;
    m -= sub;
    M -= sub;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        ll a, b;
        cin >> a >> b;
        line l(slope(a, b), b, m, i);
        v.push_back(l);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) add_line(v[i]);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        double a;
        cin >> a;
        a -= sub;
        cout << query(a) << '\n';
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