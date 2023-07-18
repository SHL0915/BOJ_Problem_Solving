#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct line {
    mutable ll a, b, x;

    bool operator<(const line &cmp) const {
        return a < cmp.a;
    }

    bool operator<(const ll cmp) const {
        return x < cmp;
    }
};

struct LineContainer : multiset<line, less<>> { // 기울기가 증가하는 순으로 정렬
    const ll INF = 1e15;

    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool intersect(iterator x, iterator y) {
        if (y == end()) return x->x = INF, 0;
        if (x->a == y->a) x->x = x->b > y->b ? INF : -INF;
        else x->x = div(y->b - x->b, x->a - y->a);
        return x->x >= y->x;
    }

    void add(ll a, ll b) {
        auto z = insert({a, b, 0}), y = z++, x = y;
        while (intersect(y, z)) z = erase(z);
        if (x != begin() && intersect(--x, y)) intersect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->x >= y->x) intersect(x, erase(y));
    }

    ll query(ll x) {
        auto l = *lower_bound(x);
        return l.a * x + l.b;
    }
};

int Q;

void solve() {
    cin >> Q;
    LineContainer A;

    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            ll x, y;
            cin >> x >> y;
            A.add(x, y);
        } else {
            ll x;
            cin >> x;
            ll ans = -0x3f3f3f3f3f3f3f3fLL;
            ans = max(ans, A.query(x));

            cout << ans << '\n';
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