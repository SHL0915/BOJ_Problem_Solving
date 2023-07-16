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

struct LineContainer : multiset<line, less<>> {
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

int N;
ll arr[100005], psum[100005];
ll pace[100005], pre[100005];
ll dp[100005];
LineContainer L;

ll slope(int i) {
    return pace[i];
}

ll intercept(int i) {
    return -pace[i] * psum[i] + pre[i] + dp[i];
}

void solve() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    for (int i = 0; i < N; i++) cin >> pre[i] >> pace[i];

    dp[0] = 0;
    L.add(-slope(0), -intercept(0));

    for (int i = 1; i < N; i++) {
        dp[i] = -L.query(psum[i]);
        L.add(-slope(i), -intercept(i));
    }

    cout << dp[N - 1];
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