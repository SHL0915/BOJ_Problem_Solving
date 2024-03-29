#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct line {
    mutable ll a, b, x;

    bool operator<(const line &cmp) const {
        return a > cmp.a;
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
        if (x->a == y->a) x->x = x->b < y->b ? INF : -INF;
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
ll dp[100005];
vector<pii> arr;

void solve() {
    cin >> N;
    arr.clear();
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        while (arr.size() && arr.back().second <= y - (x - arr.back().first)) arr.pop_back();
        if (arr.size() == 0 || y > arr.back().second - (x - arr.back().first)) arr.push_back({x, y});
    }

    N = arr.size();
    arr.push_back({0, 0});

    LineContainer L;

    L.add(-2 * (arr[0].first - arr[0].second), (arr[0].first - arr[0].second) * (arr[0].first - arr[0].second));

    for (int i = 0; i < N; i++) {
        ll a = arr[i].first + arr[i].second;
        ll b = arr[i + 1].first - arr[i + 1].second;
        dp[i] = L.query(a) + a * a;
        L.add(-2 * b, b * b + dp[i]);
    }

    ll ans = dp[N - 1];

    if (ans % 4 == 0) cout << ans / 4 << ".00\n";
    if (ans % 4 == 1) cout << ans / 4 << ".25\n";
    if (ans % 4 == 2) cout << ans / 4 << ".50\n";
    if (ans % 4 == 3) cout << ans / 4 << ".75\n";

    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}