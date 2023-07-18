#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

struct line {
    mutable ll a, b, x;

    bool operator<(const line &cmp) const {
        return a < cmp.a;
    }

    bool operator<(const ll cmp) const {
        return x < cmp;
    }
};

struct LineContainer : multiset<line, less<>> { // basic은 기울기가 큰 애들 순으로 정렬, min값 구하기
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
ll arr[300005], dp[300005], psum[300005];
ll rev[300005], rdp[300005], rpsum[300005];

ll slope(int i) {
    return arr[i];
}

ll intercept(int i) {
    return psum[i - 1] + arr[i] * (1 - i) + psum[N];
}

ll rslope(int i) {
    return rev[i];
}

ll rintercept(int i) {
    return rpsum[i - 1] + rev[i] * (1 - i) + rpsum[N];
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    ll A = -INF, B = -INF;

    LineContainer L;

    dp[1] = arr[1] + psum[N] - psum[1];
    L.add(slope(1), intercept(1));

    for (int i = 1; i <= N; i++) {
        dp[i] = L.query(i) - psum[i];
        L.add(slope(i), intercept(i));
    }

    for (int i = 1; i <= N; i++) {
        rev[i] = arr[N - i + 1];
        rpsum[i] = rev[i] + rpsum[i - 1];
    }

    LineContainer RL;

    rdp[1] = rev[1] + rpsum[N] - rpsum[1];
    RL.add(rslope(1), rintercept(1));

    for (int i = 2; i <= N; i++) {
        rdp[i] = RL.query(i) - rpsum[i];
        RL.add(rslope(i), rintercept(i));
    }

    for (int i = 2; i <= N; i++) {
        A = max(A, rdp[i]);
        B = max(B, dp[i]);
    }

    cout << A << '\n' << B;
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